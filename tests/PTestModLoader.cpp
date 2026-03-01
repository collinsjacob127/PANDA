
#define UNIT_TEST
#include <QtTest/QtTest>
#include "PModItem.h"
#include "PDatabase.h"
#include "PModQueries.h"
#include "PFileData.h"
#include "PConfigMgr.h"
#include "PApeFile.h"
#include "PModDataAccess.h"

class PTestModLoader : public QObject
{
    Q_OBJECT
private slots:
    void testLoadConfig_data();
    void testLoadConfig();
    void testModCount_data();
    void testModCount();
    void testAddMod_data();
    void testAddMod();
    void testRemoveMod_data();
    void testRemoveMod();
    void 
};

// Statics
QString testDataDir = QFINDTESTDATA("test_data/");

void PTestConfigMgr::testLoadConfig_data()
{
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<bool>("expected");

    QTest::newRow("ini config") << testDataDir + "config.ini" << true;
    QTest::newRow("toml config") << testDataDir + "config.toml" << true;
    QTest::newRow("invalid config") << testDataDir + "config_invalid.ini" << false;
    QTest::newRow("empty config") << testDataDir + "config_empty.ini" << false;
}
void PTestConfigMgr::testLoadConfig()
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

QTEST_MAIN(PTestConfigMgr)
#include "PTestConfigMgr.moc"
