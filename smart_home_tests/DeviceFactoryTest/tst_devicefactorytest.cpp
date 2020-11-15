#include <QtTest>
#include "devicefactory.h"
#include "lightswitchdevicefactory.h"
#include "thermostatdevicefactory.h"
#include "sprinklerdevicefactory.h"
#include "thermostat.h"
#include "sprinklersystem.h"
#include "lightswitch.h"


class DeviceFactoryTest : public QObject
{
    Q_OBJECT

public:
    DeviceFactoryTest();
    ~DeviceFactoryTest();
    DeviceFactory* _deviceFactory = nullptr;

private slots:

    void createLightSwitchTest();
    void createSprinklerTest();
    void createThermostatTest();


};

DeviceFactoryTest::DeviceFactoryTest()
{

}

DeviceFactoryTest::~DeviceFactoryTest()
{

}

void DeviceFactoryTest::createLightSwitchTest()
{

    LightSwitchDeviceFactory ldf("test");

    LightSwitch* _lSwitch =  dynamic_cast<LightSwitch*>(_deviceFactory->createDevice(&ldf));

     QCOMPARE(_lSwitch->deviceType(),"Light Switch");
}

void DeviceFactoryTest::createSprinklerTest()
{

    SprinklerDeviceFactory sdf("test");

    SprinklerSystem*_sprinklerSystem = dynamic_cast<SprinklerSystem*>(_deviceFactory->createDevice(&sdf));

    QCOMPARE(_sprinklerSystem->deviceType(),"Sprinkler System");


}

void DeviceFactoryTest::createThermostatTest()
{
    ThermostatDeviceFactory tdf("test");

    Thermostat* _thermoStat = dynamic_cast<Thermostat*>(_deviceFactory->createDevice(&tdf));

    QCOMPARE(_thermoStat->deviceType(),"Thermostat");

}



QTEST_APPLESS_MAIN(DeviceFactoryTest)

#include "tst_devicefactorytest.moc"
