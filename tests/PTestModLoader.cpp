#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestConfigMgr : public QObject
{
    Q_OBJECT
private slots:
    void testGetIconPngPaths_data();
    void testGetIconPngPaths();
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

QTEST_MAIN(PTestModLoader)
#include "PTestModLoader.moc"
