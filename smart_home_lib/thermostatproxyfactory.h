#ifndef THERMOSTATPROXYFACTORY_H
#define THERMOSTATPROXYFACTORY_H

#include "proxyabstractfactory.h"
#include <QString>

class ThermostatProxyFactory : public ProxyAbstractFactory
{
public:
    ThermostatProxyFactory(QString name);


    ProxyInterface *createProxy();
private:

    QString _name;
};

#endif // THERMOSTATPROXYFACTORY_H
