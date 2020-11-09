#ifndef THERMOSTATPROXY_H
#define THERMOSTATPROXY_H
#include <QString>

#include "thermostatproxyinterface.h"
#include "thermostatdevicefactory.h"
#include "devicefactory.h"
#include "thermostat.h"

class ThermostatProxy : public ThermostatProxyInterface
{
public:
    ThermostatProxy(QString name );
    // Required functions overrides here
private:

    DeviceFactory* _deviceFactory;

    Thermostat* _thermoStat;

};

#endif // THERMOSTATPROXY_H
