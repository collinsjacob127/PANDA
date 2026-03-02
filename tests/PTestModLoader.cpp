#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestModLoader : public QObject
{
    Q_OBJECT
private slots:
    void testGetIconPngPaths_data();
    void testGetIconPngPaths();
};

// Statics
QString testDataDir = QFINDTESTDATA("test_data/");

void PTestModLoader::testGetIconPngPaths_data()
{
    QTest::addColumn<QStringList>("filePathList");
    QTest::addColumn<bool>("expected");

    QTest::newRow("list of icon paths") << testDataDir + "config.ini" << true;
}

void PTestModLoader::testGetIconPngPaths()
{
    QFETCH(QString, filePath);
    QFETCH(bool, expected);

    PConfigMgr configMgr;
    bool result = configMgr.loadConfig(filePath);

    if (expected) {
        QVERIFY(result);
    } else {
        QVERIFY(!result);
    }
}

QTEST_MAIN(PTestModLoader)
#include "PTestModLoader.moc"
