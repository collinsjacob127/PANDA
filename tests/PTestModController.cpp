#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestModController : public QObject
{
    Q_OBJECT
private slots:
};

QTEST_MAIN(PTestModController)
#include "PTestModController.moc"
