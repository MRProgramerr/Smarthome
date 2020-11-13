#include <QtTest>
#include "lightswitch.h"
// add necessary includes here

class tst_LightSwitch : public QObject
{
    Q_OBJECT

public:
    tst_LightSwitch();
    ~tst_LightSwitch();

private:
    LightSwitch ls;
private slots:
   void testID();
   void testIPaddress();
   void testcurrentState();
   void testbrighten();
   void testdim();
   void testturnOn();
   void testturnOff();




};


tst_LightSwitch::tst_LightSwitch() : ls("Hussain")
{

}

tst_LightSwitch::~tst_LightSwitch()
{

}

void tst_LightSwitch::testID()
{
    ls.setDeviceName("Light Switch");
    QCOMPARE(ls.getDeviceName(),"Light Switch");
}

void tst_LightSwitch::testIPaddress()
{
    ls.setIPAddressController("LS IP");
    QCOMPARE(ls.getIPAddressController(), "LS IP");
}

void tst_LightSwitch::testcurrentState()
{

}
void tst_LightSwitch::testbrighten()
{
    ls.setBrightnessLevel(20);
    ls.brighten();
    QCOMPARE(ls.getBrightnessLevel(),40);
}
void tst_LightSwitch::testdim()
{
    ls.setBrightnessLevel(100);
    ls.dim();
    QCOMPARE(ls.getBrightnessLevel(),80);

}
void tst_LightSwitch::testturnOn()
{
    ls.turnOff();
    ls.turnOn();
    QCOMPARE(ls.getIsOn(),true);


}
void tst_LightSwitch::testturnOff()
{

    ls.turnOn();
    ls.turnOff();
    QCOMPARE(ls.getIsOn(),false);

}

QTEST_MAIN(tst_LightSwitch)

#include "tst_lightswitch.moc"
