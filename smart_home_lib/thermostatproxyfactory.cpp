#include "thermostatproxyfactory.h"
#include "thermostatproxy.h"

ThermostatProxyFactory::ThermostatProxyFactory(QString name) : _name(name)
{

}

ProxyInterface *ThermostatProxyFactory::createProxy()
{
    return new ThermostatProxy(_name);
}
