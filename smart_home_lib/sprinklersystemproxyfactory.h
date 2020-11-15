#ifndef SPRINKLERSYSTEMPROXYFACTORY_H
#define SPRINKLERSYSTEMPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include "QString"

/**
 * @brief The SprinklerSystemProxyFactory class
 * A concrete factory for creating sprinkler system proxies
 */

class SprinklerSystemProxyFactory : public ProxyAbstractFactory
{
public:

    /**
     * @brief SprinklerSystemProxyFactory
     * @param name
     */
    SprinklerSystemProxyFactory(QString name);

    /**
     * @brief createProxy
     * @return A sprinkler system proxy
     */
    ProxyInterface *createProxy();

private:

    QString _name;

};

#endif // SPRINKLERSYSTEMPROXYFACTORY_H
