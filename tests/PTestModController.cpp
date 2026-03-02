#define UNIT_TEST

#include <QtTest/QtTest>
#include "PModController.h"
#include "PDatabaseMgr.h"

class PTestModController : public QObject
{
    Q_OBJECT
private slots:
    // init and cleanup
    void initTestCase();
    void cleanupTestCase();
    // tests
    void testRemoveMod_data();
    void testRemoveMod();
};

void PTestModController::initTestCase()
{
    // cleanup any existing test mod entries in the database before starting tests
    if (PDatabaseMgr().doesModExist("test-mod-id")) {
        PDatabaseMgr db;
        db.openDatabase();
        db.deleteMod("test-mod-id");
        db.closeDatabase();
    }
    // create a dummy mod entry inside of database to test with
    PDatabaseMgr db;
    db.openDatabase();
    PModItem mod;
    mod.setId("test-mod-id");
    mod.setTitle("Test Mod");
    mod.setAuthors({"Test Author"});
    mod.setDescription("This is a test mod.");
    mod.setVersion("1.0.0");
    // test location /test_cases/testmod.ztd
    mod.setFilename("testmod.ztd");
    mod.setEnabled(true);
    mod.setCategory("Test");
    mod.setTags({"Test", "Example"});
    mod.setCurrentLocation("test_cases/");
    mod.setIconPaths({"test_cases/testmod_icon.png"});
    mod.setSelected(false);
    db.insertMod(mod);
    db.closeDatabase();
}

void PTestModController::cleanupTestCase()
{
    // remove the dummy mod entry from the database

    // check if mod exists before attempting to delete
    if (!PDatabaseMgr().doesModExist("test-mod-id")) {
        return;
    }
    PDatabaseMgr db;
    db.openDatabase();
    db.deleteMod("test-mod-id");
    db.closeDatabase();
}

void PTestModController::testRemoveMod_data()
{
    QTest::addColumn<QString>("modId");
    QTest::addColumn<bool>("expected");

    QTest::newRow("Remove existing mod") << "test-mod-id" << true;
    QTest::newRow("Remove non-existing mod") << "non-existing-mod-id" << false;
}

void PTestModController::testRemoveMod()
{
    QFETCH(QString, modId);
    QFETCH(bool, expected);

    PDatabaseMgr db;
    db.openDatabase();
    QSharedPointer<PModItem> mod = db.getModByPk(modId);
    db.closeDatabase();

    if (!mod) {
        qDebug() << "Mod not found in database: " << modId;
        QCOMPARE(false, expected);
        return;
    }

    PModController controller;
    controller.removeMod(mod);

    // check if the mod was deleted from the database
    bool existsInDb = PDatabaseMgr().doesModExist(modId);
    QCOMPARE(!existsInDb, expected);

    // check if the mod file was deleted from the filesystem
    QString filePath = mod->location() + "/" + mod->filename();
    bool fileExists = QFile::exists(filePath);
    QCOMPARE(!fileExists, expected);
}

QTEST_MAIN(PTestModController)
#include "PTestModController.moc"
