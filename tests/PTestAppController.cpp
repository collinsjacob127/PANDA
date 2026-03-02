#define UNIT_TEST

#include <QtTest/QtTest>
#include "PConfigMgr.h"

class PTestAppController : public QObject
{
    Q_OBJECT
private slots:
};

QTEST_MAIN(PTestAppController)
#include "PTestAppController.moc"
