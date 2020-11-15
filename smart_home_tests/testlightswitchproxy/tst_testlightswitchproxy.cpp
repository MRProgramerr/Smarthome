#include <QtTest>
#include "lightswitchproxy.h"
#include "lightswitch.h"
// add necessary includes here

class LightSwitchProxyTest : public QObject
{
    Q_OBJECT

public:
    LightSwitchProxyTest();
    ~LightSwitchProxyTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testturnOn();
    void testturnOff();
    void testbrighten();
    void testdim();
    void testisOn();
    void testsetPortController();
    void testsetIPAddressController();
    void testrealDevice();
    void testbrightnessStatus();

};

LightSwitchProxyTest::LightSwitchProxyTest()
{

}

LightSwitchProxyTest::~LightSwitchProxyTest()
{

}

void LightSwitchProxyTest::initTestCase()
{

}

void LightSwitchProxyTest::cleanupTestCase()
{

}

void LightSwitchProxyTest::testturnOn()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.turnOff();
    lp.turnOn();
    QCOMPARE(lp.getIsOn(),true);
}

void LightSwitchProxyTest::testturnOff()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.turnOn();
    lp.turnOff();
    QCOMPARE(lp.getIsOn(),false);
}

void LightSwitchProxyTest::testbrighten()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.brighten();
    QCOMPARE(lp.brightnessStatus(),20);
}

void LightSwitchProxyTest::testdim()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.brighten();
    lp.dim();
    QCOMPARE(lp.brightnessStatus(),0);
}

void LightSwitchProxyTest::testisOn()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.turnOn();
    QCOMPARE(lp.getIsOn(), true);
    lp.turnOff();
    QCOMPARE(lp.getIsOn(), false);
    lp.turnOn();
    QCOMPARE(lp.getIsOn(), true);
}

void LightSwitchProxyTest::testsetPortController()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    QString port = "Test";
    lp.setPortController(port);
    QCOMPARE(lp.realDevice()->getPortNumberController(), port );
}

void LightSwitchProxyTest::testsetIPAddressController()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    QString IP = "Test";
    lp.setIPAddressController(IP);
    QCOMPARE(lp.realDevice()->getIPAddressController(), IP);
}

void LightSwitchProxyTest::testrealDevice()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    std::string type = "Light Switch";

    QCOMPARE(lp.realDevice()->deviceType(), type);
    QCOMPARE(lp.realDevice()->getDeviceName(), name);
}

void LightSwitchProxyTest::testbrightnessStatus()
{
    QString name = "Test";
    LightSwitchProxy lp(name);
    lp.brighten();
    MeasurementTemplate<int> brightness("LightSwitch","Power","%");
    brightness.setValue(20);
     QCOMPARE(lp.brightnessStatus(), brightness);
}





QTEST_APPLESS_MAIN(LightSwitchProxyTest);

#include "tst_testlightswitchproxy.moc"
