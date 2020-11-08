#include "lightswitchproxyfactory.h"
#include "proxyinterface.h"
#include "lightswitchproxy.h"

LightSwitchProxyFactory::LightSwitchProxyFactory(QString name) : _name(name)
{

}

ProxyInterface LightSwitchProxyFactory::createProxy()
{

    LightSwitchProxy lsp(_name);

    return std::move(lsp);


}
