#include <QtTest>
#include "sprinklersystem.h"
#include <QVariant>

// add necessary includes here

class SprinklerTest : public QObject
{
    Q_OBJECT

public:
    SprinklerTest();
    ~SprinklerTest();

private slots:
    void setUpdateFrequencyTest();
    void setWaterConsumptionPerIntervalTest();
    void getIsOnTest();
    void turnOnTest();
    void turnOffTest();
    void deviceTypeTest();
    void currentStateTest();

};

SprinklerTest::SprinklerTest()
{

}

SprinklerTest::~SprinklerTest()
{

}

void SprinklerTest::setUpdateFrequencyTest()
{
    int expected{20};
    SprinklerSystem test("test");
    test.setUpdateFrequency(expected);
    QCOMPARE(test.getUpdateFrequency(),expected);


}

void SprinklerTest::setWaterConsumptionPerIntervalTest()
{

    int expected{30};
    SprinklerSystem test("test");
    test.setWaterConsumptionPerInterval(expected);
    QCOMPARE(test.getWaterConsumptionPerInterval(),expected);

}

void SprinklerTest::getIsOnTest()
{
    SprinklerSystem test("test");
    test.turnOn();

    QCOMPARE(test.getIsOn(),true);

    test.turnOff();

    QCOMPARE(test.getIsOn(),false);

}

void SprinklerTest::turnOnTest()
{

    SprinklerSystem test("test");
    test.turnOn();
    QCOMPARE(test.getIsOn(),true);

}

void SprinklerTest::turnOffTest()
{

    SprinklerSystem test("test");
    test.turnOff();
    QCOMPARE(test.getIsOn(),false);

}


void SprinklerTest::deviceTypeTest()
{
    SprinklerSystem test("test");
    QCOMPARE(test.deviceType(),"Sprinkler System");
}

void SprinklerTest::currentStateTest()
{

    SprinklerSystem test("test");
    test.setcurrrentState("SCHEDULED");

    QCOMPARE((int)test.currentState().size(),3);

}



QTEST_APPLESS_MAIN(SprinklerTest)

#include "tst_sprinklertest.moc"
