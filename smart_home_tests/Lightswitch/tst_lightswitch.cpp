#include <QtTest>
#include "lightswitch.h"
// add necessary includes here

class lightswitch : public QObject
{
    Q_OBJECT

public:
    lightswitch();
    ~lightswitch();
private:
    LightSwitch ls;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testturnOn();
    void testturnOff();
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testbrighten();
    void testdim();

};


lightswitch::lightswitch() : ls("test")
{

}

lightswitch::~lightswitch()
{

}

void lightswitch::initTestCase()
{

}

void lightswitch::cleanupTestCase()
{

}

void lightswitch::testturnOn()
{

    ls.turnOff();
        ls.turnOn();
        QCOMPARE(ls.getIsOn(),true);

}
void lightswitch::testturnOff()
{

    ls.turnOn();
    ls.turnOff();
    QCOMPARE(ls.getIsOn(),false);

}

void lightswitch::testID()
{
    ls.setDeviceName("Light Switch");
    QCOMPARE(ls.getDeviceName(),"Light Switch");
}

void lightswitch::testIPaddress()
{
    ls.setIPAddressController("LS IP");
    QCOMPARE(ls.getIPAddressController(), "LS IP");
}

void lightswitch::testcurrentState()
{

}

void lightswitch::testbrighten()
{
    ls.setBrightnessLevel(20);
      ls.brighten();
      QCOMPARE(ls.getBrightnessLevel(),40);
}

void lightswitch::testdim()
{
    ls.setBrightnessLevel(100);
        ls.dim();
        QCOMPARE(ls.getBrightnessLevel(),80);
}

QTEST_APPLESS_MAIN(lightswitch)

#include "tst_lightswitch.moc"
