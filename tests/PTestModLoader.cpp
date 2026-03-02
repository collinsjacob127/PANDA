#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestModLoader : public QObject
{
    Q_OBJECT
private slots:
    void testGetZtdList_data();
    void testGetZtdList();
    void testLoadModsFromFile_data();
    void testLoadModsFromFile();
    void testDeleteIcons_data();
    void testDeleteIcons();
    void testBuildCollectionMods_data();
    void testBuildCollectionMods();
    void testBuildModFromToml_data();
    void testBuildModFromToml();
    void testBuildDefaultMod_data();
    void testBuildDefaultMod();
    void testGenerateFileData_data();
    void testGenerateFileData();
    void testGenerateTagsFromConfig_data();
    void testGenerateTagsFromConfig();
    void testDetermineCategory_data();
    void testDetermineCategory();
    void testGetIconPngPaths_data();
    void testGetIconPngPaths();

    void testGetIconAniPaths_data();
    void testGetIconAniPaths();
    void testGetIconPaths_data();
    void testGetIconPaths();
    void testBuildGraphicPath_data();
    void testBuildGraphicPath();
    void testDetermineDescription_data();
    void testDetermineDescription();
    void testDetermineTitle_data();
    void testDetermineTitle();
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
