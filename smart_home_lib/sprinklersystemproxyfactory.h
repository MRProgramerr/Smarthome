#ifndef SPRINKLERSYSTEMPROXYFACTORY_H
#define SPRINKLERSYSTEMPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include "QString"

class SprinklerSystemProxyFactory : public ProxyAbstractFactory
{
public:
    SprinklerSystemProxyFactory(QString name);

    ProxyInterface *createProxy();

private:

    QString _name;

};

#endif // SPRINKLERSYSTEMPROXYFACTORY_H
