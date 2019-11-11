#include <QtTest>

#include "typeprogresscontroller.h"

class TestTypeProgressController : public QObject
{
    Q_OBJECT

public:

    TestTypeProgressController(){}
    virtual ~TestTypeProgressController(){}

private slots:

    void computeProgress()
    {
        TypeProgressController ctrl;
        ctrl.text = "This is a simple test";
        QCOMPARE(ctrl.computeProgress("This") , 4/21.);
        QCOMPARE(ctrl.computeProgress("Thos") , 2/21.);

        QCOMPARE(ctrl.computeProgressString("")     ,QString(""));
        QCOMPARE(ctrl.computeProgressString("This") ,QString("<color=green>This</color>"));
        QCOMPARE(ctrl.computeProgressString("Tazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdahis") ,
                 QString("<color=green>T</color><color=grey>azdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdahis</color>"));
    }
};


QTEST_APPLESS_MAIN(TestTypeProgressController)
#include "tst_testtypeprogresscontroller.moc"

