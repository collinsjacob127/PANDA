#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestModLoader : public QObject
{
    Q_OBJECT
private slots:
};

QTEST_MAIN(PTestModLoader)
#include "PTestModLoader.moc"
