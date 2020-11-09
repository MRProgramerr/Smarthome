#ifndef LIGHTSWITCHPROXYFACTORY_H
#define LIGHTSWITCHPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include <QString>

class LightSwitchProxyFactory : public ProxyAbstractFactory
{
public:
    LightSwitchProxyFactory(QString name);

    ProxyInterface* createProxy();

private:
    QString _name;
};

#endif // LIGHTSWITCHPROXYFACTORY_H
