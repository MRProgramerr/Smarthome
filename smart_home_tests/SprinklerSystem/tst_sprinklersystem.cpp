#include <QtTest>
#include "sprinklersystem.h"
// add necessary includes here

class sprinklersystem : public QObject
{
    Q_OBJECT

public:
    sprinklersystem();
    ~sprinklersystem();
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

sprinklersystem::sprinklersystem() : ss("test3")
{

}

sprinklersystem::~sprinklersystem()
{

}

void sprinklersystem::testturnOn()
{

    ss.turnOff();
        ss.turnOn();
        QCOMPARE(ss.getIsOn(),true);

}
void sprinklersystem::testturnOff()
{

    ss.turnOn();
    ss.turnOff();
    QCOMPARE(ss.getIsOn(),false);

}

void sprinklersystem::testschedule()
{

}

void sprinklersystem::testwaterUsage()
{

}

void sprinklersystem::testID()
{
    ss.setDeviceName("Sprinkler System");
    QCOMPARE(ss.getDeviceName(),"Sprinkler System");
}

void sprinklersystem::testIPaddress()
{
    ss.setIPAddressController("SS IP");
    QCOMPARE(ss.getIPAddressController(), "SS IP");
}

void sprinklersystem::testcurrentState()
{

}


QTEST_APPLESS_MAIN(sprinklersystem)

#include "tst_sprinklersystem.moc"
