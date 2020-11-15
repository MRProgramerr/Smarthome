#include <QtTest>
#include "proxyfactory.h"
#include "lightswitchproxyfactory.h"
#include "thermostatproxyfactory.h"
#include "sprinklersystemproxyfactory.h"
#include "lightswitchproxy.h"
#include "thermostatproxy.h"
#include "sprinklersystemproxy.h"

// add necessary includes here

class ProxyFactoryTest : public QObject
{
    Q_OBJECT

public:
    ProxyFactoryTest();
    ~ProxyFactoryTest();
    ProxyFactory* _proxyFactory = nullptr;

private slots:
    void createLightSwitchProxyTest();
    void createSprinklerProxyTest();
    void createThermostatProxyTest();

};

ProxyFactoryTest::ProxyFactoryTest()
{

}

ProxyFactoryTest::~ProxyFactoryTest()
{

}

void ProxyFactoryTest::createLightSwitchProxyTest()
{
    LightSwitchProxyFactory lpf("test");
    LightSwitchProxy* lProxy =  dynamic_cast<LightSwitchProxy*>( _proxyFactory->createProxy(&lpf));
    QCOMPARE(lProxy->realDevice()->deviceType(),"Light Switch");

}

void ProxyFactoryTest::createSprinklerProxyTest()
{

    SprinklerSystemProxyFactory spf("test");
    SprinklerSystemProxy* sProxy =  dynamic_cast<SprinklerSystemProxy*>( _proxyFactory->createProxy(&spf));
    QCOMPARE(sProxy->realDevice()->deviceType(),"Sprinkler System");

}

void ProxyFactoryTest::createThermostatProxyTest()
{
    ThermostatProxyFactory tpf("test");
    ThermostatProxy* tProxy =  dynamic_cast<ThermostatProxy*>( _proxyFactory->createProxy(&tpf));
    QCOMPARE(tProxy->realDevice()->deviceType(),"Thermostat");

}



QTEST_APPLESS_MAIN(ProxyFactoryTest)

#include "tst_proxyfactorytest.moc"
