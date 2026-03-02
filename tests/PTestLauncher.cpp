#define UNIT_TEST

#include <QtTest/QtTest>

class PTestLauncher : public QObject
{
    Q_OBJECT
private slots:
};

QTEST_MAIN(PTestLauncher)
#include "PTestLauncher.moc"
