#ifndef THERMOSTATPROXYFACTORY_H
#define THERMOSTATPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include <QString>

/**
 * @brief The ThermostatProxyFactory class
 * A concrete factory for creating thermostat proxies
 */


class ThermostatProxyFactory : public ProxyAbstractFactory
{
public:

    /**
     * @brief ThermostatProxyFactory
     * @param name of the proxy
     */
    ThermostatProxyFactory(QString name);

    /**
     * @brief createProxy
     * @return A thermostat proxy
     */
    ProxyInterface *createProxy();

private:

    QString _name;
};

#endif // THERMOSTATPROXYFACTORY_H
