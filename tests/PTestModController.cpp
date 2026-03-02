#define UNIT_TEST

#include <QtTest/QtTest>
#include "PModController.h"

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
    mod.setLocation("test_cases");
    mod.setFilename("testmod.ztd");
    mod.setEnabled(true);
    mod.setCategory("Test");
    mod.setTags({"Test", "Example"});
    mod.setOGLocation("test_cases/testmod.ztd");
    mod.setIconPaths({"test_cases/testmod_icon.png"});
    mod.setSelected(false);
    db.insertMod(mod);
    db.closeDatabase();
}


QTEST_MAIN(PTestModController)
#include "PTestModController.moc"
