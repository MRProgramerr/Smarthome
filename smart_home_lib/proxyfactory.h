#ifndef PROXYFACTORY_H
#define PROXYFACTORY_H

#include "proxyinterface.h"
#include "proxyabstractfactory.h"

/**
 * @brief The ProxyFactory class
 * Uses abstract proxy factories to create
 * concrete proxies
 */

class ProxyFactory
{
public:
    ProxyFactory();

    /**
     * @brief createProxy
     * @param paf : The proxy abstract factory required to create the approproiate proxy
     * @return a proxy object
     */
    ProxyInterface* createProxy(ProxyAbstractFactory* paf);



};

#endif // PROXYFACTORY_H
