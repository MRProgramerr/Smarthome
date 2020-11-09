#include "thermostatproxy.h"

ThermostatProxy::ThermostatProxy(QString name)
{

    ThermostatDeviceFactory tdf(name);

    _thermoStat = dynamic_cast<Thermostat*>(_deviceFactory->createDevice(&tdf));

}
