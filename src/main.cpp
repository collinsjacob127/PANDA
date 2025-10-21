// Qt
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QJSValue>
#include <QQmlContext>
#include <QQmlEngine>
// error logging
#include <QDebug>
#include <QDir>

// Project
#include "PModUIController.h"
#include "PModItem.h"
#include "PModLoader.h"
#include "PConfigMgr.h"
#include "PModQueries.h"
#include "PDatabase.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Register the PAppController singleton
    // PAppController *p_state = new PAppController(&app);
    // qmlRegisterSingletonInstance("PandaLdr", 1, 0, "PAppController", p_state);

    // Register the PModUIController singleton

    // print log to file
    QFile logFile(QDir::homePath() + "/.panda/log.txt");
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&logFile);
        out << "PandaLdr started\n";
    }
    qInstallMessageHandler([](QtMsgType type, const QMessageLogContext &context, const QString &msg) {
        QFile logFile(QDir::homePath() + "/.panda/log.txt");
        if (logFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&logFile);
            out << msg << "\n";
        }
    });

    // --------------------- CREATE CORE OBJECTS ---------------------
    QSharedPointer<PLauncher> launcher = QSharedPointer<PLauncher>::create();
    QSharedPointer<PDatabase> pandaDb = QSharedPointer<PDatabase>::create(QDir::homePath() + "/.panda", "ModsDb",
                                                                          QStringList{PQueries::CreateModsTable, PQueries::CreateDependenciesTable});
    qDebug() << "Created PDatabase";
    qDebug() << "Created PDatabase with tables";

    // --------------------- CREATE MOD CONTROLLER ---------------------
    // earlier than other controllers because other controllers may depend on it
    QSharedPointer<PModUIController> modController = QSharedPointer<PModUIController>::create(&app, pandaDb);
    qDebug() << "Created PModUIController";

    // --------------------- LOAD MODS FROM DATABASE ---------------------
    modController->loadMods();
    qDebug() << "Loaded mods into PModUIController";

    // ---------------------- SET CONTEXT PROPERTIES ---------------------
    // context properties are the objects accessible from QML
    QSharedPointer<PAppController> state = QSharedPointer<PAppController>::create(&app);
    QSharedPointer<PConfigMgr> zoo = state->m_zooini;
    QSharedPointer<PConfigMgr> settings = state->m_pandacfg;
    engine.rootContext()->setContextProperty("modController", modController.get());
    engine.rootContext()->setContextProperty("modModel", modController->model());
    engine.rootContext()->setContextProperty("state", state.get());
    engine.rootContext()->setContextProperty("psettings", settings.get());
    engine.rootContext()->setContextProperty("zoo", zoo.get());
    engine.rootContext()->setContextProperty("launcher", launcher.get());
    qDebug() << "Set context properties";

    // --------------------- REGISTER TYPES ---------------------
    qmlRegisterAnonymousType<QAbstractListModel>("PandaLdr", 1); // for mod list model
    qmlRegisterType<PModItem>("PandaLdr", 1, 0, "PModItem"); // for mod item
    qRegisterMetaType<PModItem*>("PModItem*"); // for signals/slots
    qRegisterMetaType<PModItem*>("QSharedPointer<PModItem>"); // for signals/slots
    qmlRegisterUncreatableType<PModItem>("PandaLdr", 1, 0, "PModItem", "PModItem can only be created in C++"); // prevent QML instantiation
    qDebug() << "Registered PModItem type"; // for logging

    // --------------------- REGISTER CONTROLLERS ---------------------
    // qRegisterMetaType<PModList*>("PModList*");
    // qmlRegisterType<PModList>("PandaLdr", 1, 0, "PModList");
    qmlRegisterType<PModUIController>("PandaLdr", 1, 0, "PModUIController");
    qDebug() << "Registered PModUIController type";

    // --------------------- START QML ENGINE ---------------------
    qDebug() << "Loading QML file";
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
        engine.addImportPath(":/");
        engine.addImportPath(QCoreApplication::applicationDirPath());
        const QUrl url(QStringLiteral("file:///") + QCoreApplication::applicationDirPath() + "/PandaUI/ui/Main.qml");
        engine.load(url);



    return app.exec();
}
