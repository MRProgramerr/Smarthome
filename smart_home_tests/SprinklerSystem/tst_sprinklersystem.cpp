#include <QtTest>
#include <QCoreApplication>
#include "sprinklersystem.h"
// add necessary includes here

class tst_sprinklersystem : public QObject
{
    Q_OBJECT

public:
    tst_sprinklersystem();
    ~tst_sprinklersystem();
private:
    SprinklerSystem ss;
private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testturnOn();
    void testturnOff();
    void testschedule();
    void testwaterUsage();
};
tst_sprinklersystem::tst_sprinklersystem() : ss("shiv")
{

}

tst_sprinklersystem::~tst_sprinklersystem()
{

}
void tst_sprinklersystem::testID()
{
    ss.setDeviceName("Sprinkler");
    QCOMPARE(ss.getDeviceName(), "Sprinkler");
}
void tst_sprinklersystem::testIPaddress()
{
    ss.setIPAddressController("Sprinkler IP");
    QCOMPARE(ss.getIPAddressController(), "Sprinkler IP");
}
void tst_sprinklersystem::testcurrentState()
{
    ss.setcurrrentState("null");

}
void tst_sprinklersystem::testturnOn()
{
    ss.turnOff();
    ss.turnOn();
    QCOMPARE(ss.getIsOn(),true);

}
void tst_sprinklersystem::testturnOff()
{
    ss.turnOn();
    ss.turnOff();
    QCOMPARE(ss.getIsOn(),false);
}
void tst_sprinklersystem::testschedule()
{
    ss.turnOff();
    ss.turnOn();
    QCOMPARE(ss.currentState(), "SCHEDULED");
}
void tst_sprinklersystem::testwaterUsage()
{

}



QTEST_MAIN(tst_sprinklersystem)

#include "tst_sprinklersystem.moc"
