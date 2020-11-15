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
      void cleanupTestCase();
      void testUpdateFrequency();
      void testWaterConsumptionPerInterval();
      void testlifetimeConsumption();
      void testturnOn();
      void testturnOff();
      void testschedule();
      void testcurrrentState();
      void testwaterUsage();

private slots:
    void test_case1();

};

testsprinklersystemproxy::testsprinklersystemproxy()
{

}

testsprinklersystemproxy::~testsprinklersystemproxy()
{

}

void testsprinklersystemproxy::test_case1()
{

}

void testsprinklersystemproxy::cleanupTestCase()
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
    QTime delay(0, 0, 10);
    QTime duration(0, 0, 10);
    sp.schedule(delay, duration);
    QCOMPARE(sp.getIsOn(),false);
}

void testsprinklersystemproxy::testcurrrentState()
{
    QString name = "Test";
    SprinklerSystemProxy sp(name);
    QTime delay(0, 0, 10);
    QTime duration(0, 0, 10);
    std::vector<MeasurementTemplate<QTime>*> mtvectorstate;
    MeasurementTemplate<QTime> *mtstate = nullptr;
    MeasurementTemplate<QTime> *mtstate2 = nullptr;
    MeasurementTemplate<QTime> *mtstate3 = nullptr;
    mtstate = new MeasurementTemplate<QTime>(name.toStdString(),"Current State","SCHEDULED");
    mtvectorstate.push_back(mtstate);
    mtstate2 = new MeasurementTemplate<QTime>(name.toStdString(),"Delay","Seconds");
    mtstate->setValue(delay);
    mtvectorstate.push_back(mtstate);
    mtstate3 = new MeasurementTemplate<QTime>(name.toStdString(),"Duration","Seconds");
    mtvectorstate.push_back(mtstate);

    sp.schedule(delay, duration);
    QCOMPARE(sp.currentState(), mtvectorstate);
}

void testsprinklersystemproxy::testwaterUsage()
{
    QString name = "Test";
    double water = 20.0;
    double lifetime = 100.0;
    SprinklerSystemProxy sp(name);
    std::vector<MeasurementTemplate<double>*> mtvectorusage;
    MeasurementTemplate<double> *mtusage = nullptr;
    MeasurementTemplate<double> *mtusage2 = nullptr;
    mtusage = new MeasurementTemplate<double>(name.toStdString(),"Water Usage","L");
    mtusage->setValue(water);
    mtvectorusage.push_back(mtusage);
    mtusage2 = new MeasurementTemplate<double>(name.toStdString(),"Lifetime Water Consumption","L");
    mtusage->setValue(lifetime);
    mtvectorusage.push_back(mtusage);

    sp.setWaterConsumptionPerInterval(20.0);
    sp.setlifetimeConsumption(100.0);
    QCOMPARE(sp.waterUsage(), mtvectorusage);
}


QTEST_APPLESS_MAIN(testsprinklersystemproxy)

#include "tst_testsprinklersystemproxy.moc"
