#ifndef PROXYABSTRACTFACTORY_H
#define PROXYABSTRACTFACTORY_H

#include "proxyinterface.h"

class ProxyAbstractFactory
{
public:

    virtual ~ProxyAbstractFactory(){};

    virtual ProxyInterface* createProxy() = 0 ;

};

#endif // PROXYABSTRACTFACTORY_H
