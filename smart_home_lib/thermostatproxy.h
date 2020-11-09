#ifndef THERMOSTATPROXY_H
#define THERMOSTATPROXY_H
#include <QString>

#include "thermostatproxyinterface.h"

class ThermostatProxy : public ThermostatProxyInterface
{
public:
    ThermostatProxy(QString name );
    // Required functions overrides here
};

#endif // THERMOSTATPROXY_H
