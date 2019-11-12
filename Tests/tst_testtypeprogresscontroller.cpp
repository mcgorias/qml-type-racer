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
        TypeProgressController ctrl("This is a simple test");

        ctrl.setInput("This");
        QCOMPARE(ctrl.getProgress(), 4/21.);
        QCOMPARE(ctrl.getProgressText() ,QString(TypeProgressController::coloredText("This",ctrl.goodColor)));

        ctrl.setInput("Thos");
        QCOMPARE(ctrl.getProgressText(),QString(TypeProgressController::coloredText("Th",ctrl.goodColor)+TypeProgressController::coloredText("os",ctrl.wrongColor)));
        QCOMPARE(ctrl.getProgress() , 2/21.);

        ctrl.setInput("");
        QCOMPARE(ctrl.getProgressText(),QString(""));
        QCOMPARE(ctrl.getProgress() , 0/21.);

        ctrl.setInput("Tazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdahis");

        QCOMPARE(ctrl.getProgressText(),TypeProgressController::coloredText("T",ctrl.goodColor)+TypeProgressController::coloredText("azdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdazdahis",ctrl.wrongColor));
        QCOMPARE(ctrl.getProgress(), 1/21.);
    }
};


QTEST_APPLESS_MAIN(TestTypeProgressController)
#include "tst_testtypeprogresscontroller.moc"

