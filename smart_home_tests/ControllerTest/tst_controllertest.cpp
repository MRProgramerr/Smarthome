#include <QtTest>
#include "controller.h"

// add necessary includes here

class ControllerTest : public QObject
{
    Q_OBJECT

public:
    ControllerTest();
    ~ControllerTest();

private slots:

    void registerDeviceTest();

    void unregisterDeviceTest();
    void deviceTypeTest();


};

ControllerTest::ControllerTest()
{

}

ControllerTest::~ControllerTest()
{

}

void ControllerTest::registerDeviceTest()
{
    Controller c("test");

    c.registerDevice("DeviceTest","LightSwitch","10.10.10.1");

    std::string name = c.getListDevices().at(0)->realDevice()->getDeviceName().toStdString();

    QCOMPARE(name,"DeviceTest");


}

void ControllerTest::unregisterDeviceTest()
{
    Controller c("test");

    c.registerDevice("DeviceTest","LightSwitch","10.10.10.1");
    c.unregisterDevice("DeviceTest");

    QCOMPARE(c.registeredDevices().size(),0);


}

void ControllerTest::deviceTypeTest()
{
    Controller c("test");
    QCOMPARE(c.deviceType(),"Controller");

}



QTEST_APPLESS_MAIN(ControllerTest)

#include "tst_controllertest.moc"
