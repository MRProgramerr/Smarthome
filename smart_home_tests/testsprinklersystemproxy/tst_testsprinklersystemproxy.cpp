#include <QtTest>
#include "sprinklersystemproxy.h"
#include "sprinklersystem.h"

// add necessary includes here

class testsprinklersystemproxy : public QObject
{
    Q_OBJECT

public:
    testsprinklersystemproxy();
    ~testsprinklersystemproxy();


private slots:



    void testUpdateFrequency();
    void testWaterConsumptionPerInterval();
    void testlifetimeConsumption();
    void testturnOn();
    void testturnOff();
    void testschedule();
};

testsprinklersystemproxy::testsprinklersystemproxy()
{

}

testsprinklersystemproxy::~testsprinklersystemproxy()
{

}



void testsprinklersystemproxy::testUpdateFrequency()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.setUpdateFrequency(20);
    QCOMPARE(sp.getUpdateFrequency(),20);
}

void testsprinklersystemproxy::testWaterConsumptionPerInterval()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.setWaterConsumptionPerInterval(20.0);
    QCOMPARE(sp.getWaterConsumptionPerInterval(),20.0);
}

void testsprinklersystemproxy::testlifetimeConsumption()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.setlifetimeConsumption(100.0);
    QCOMPARE(sp.getlifetimeConsumption(),100.0);
}

void testsprinklersystemproxy::testturnOn()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.turnOff();
    sp.turnOn();
    QCOMPARE(sp.getIsOn(),true);
}

void testsprinklersystemproxy::testturnOff()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.turnOn();
    sp.turnOff();
    QCOMPARE(sp.getIsOn(),false);
}

void testsprinklersystemproxy::testschedule()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    sp.turnOn();
    QTime delay(0, 0, 1);
    QTime duration(0, 0, 1);
    sp.schedule(delay, duration);
    QCOMPARE(sp.getIsOn(),false);
}




QTEST_APPLESS_MAIN(testsprinklersystemproxy)

#include "tst_testsprinklersystemproxy.moc"
