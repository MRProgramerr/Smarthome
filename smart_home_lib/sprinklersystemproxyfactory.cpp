#include "sprinklersystemproxyfactory.h"
#include "sprinklersystemproxy.h"
#include "proxyinterface.h"

SprinklerSystemProxyFactory::SprinklerSystemProxyFactory(QString name) : _name(name)
{

}

ProxyInterface *SprinklerSystemProxyFactory::createProxy()
{
    return new SprinklerSystemProxy(_name);
}

