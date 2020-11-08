#ifndef PROXYFACTORY_H
#define PROXYFACTORY_H

#include "proxyinterface.h"
#include "proxyabstractfactory.h"

class ProxyFactory
{
public:
    ProxyFactory();

    ProxyInterface createProxy(ProxyAbstractFactory paf);



};

#endif // PROXYFACTORY_H
