#include "lightswitchproxyfactory.h"
#include "proxyinterface.h"
#include "lightswitchproxy.h"

LightSwitchProxyFactory::LightSwitchProxyFactory(QString name) : _name(name)
{

}

ProxyInterface* LightSwitchProxyFactory::createProxy()
{

    return new LightSwitchProxy(_name);


}
