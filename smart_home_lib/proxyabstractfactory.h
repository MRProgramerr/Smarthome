#ifndef PROXYABSTRACTFACTORY_H
#define PROXYABSTRACTFACTORY_H

#include "proxyinterface.h"

/**
 * @brief The ProxyAbstractFactory class
 * The absract device factory class used for the
 * abstract factory pattern to create proxies.
 */

class ProxyAbstractFactory
{
public:

    /**
     * @brief ~ProxyAbstractFactory
     * The virtual destructor for the proxy abstract factory
     */
    virtual ~ProxyAbstractFactory(){};

    /**
     * @brief createProxy
     * This methods creates a concrete proxy and is overriden
     * at appropriate levels
     * @return
     */
    virtual ProxyInterface* createProxy() = 0 ;

};

#endif // PROXYABSTRACTFACTORY_H
