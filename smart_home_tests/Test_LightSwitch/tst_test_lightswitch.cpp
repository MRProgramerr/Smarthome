#include <QtTest>
#include "lightswitch.h"

// add necessary includes here

class Test_LightSwitch : public QObject
{
    Q_OBJECT


public:
    Test_LightSwitch();
    ~Test_LightSwitch();


private slots:
    void test_case1();
    void test_LS_turnOn();

};

Test_LightSwitch::Test_LightSwitch()
{

}

Test_LightSwitch::~Test_LightSwitch()
{

}

void Test_LightSwitch::test_case1()
{

}

void Test_LightSwitch::test_LS_turnOn()
{
    LightSwitch l("test");
    l.turnOff();
    l.turnOn();
    QCOMPARE(l.getIsOn(),true);

}



QTEST_APPLESS_MAIN(Test_LightSwitch)

#include "tst_test_lightswitch.moc"
