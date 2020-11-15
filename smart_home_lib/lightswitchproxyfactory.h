#ifndef LIGHTSWITCHPROXYFACTORY_H
#define LIGHTSWITCHPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include <QString>

/**
 * @brief The LightSwitchProxyFactory class
 * A concrete factory for creating light switch proxies
 */

class LightSwitchProxyFactory : public ProxyAbstractFactory
{
public:

    /**
     * @brief LightSwitchProxyFactory
     * The constructor for light switch proxy factory
     * @param name
     */
    LightSwitchProxyFactory(QString name);

    /**
     * @brief createProxy
     * @return A light switch proxy
     */
    ProxyInterface* createProxy();

private:
    QString _name;
};

#endif // LIGHTSWITCHPROXYFACTORY_H
