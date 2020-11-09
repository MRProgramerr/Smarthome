#include "thermostatdevicefactory.h"

#include "thermostat.h"

ThermostatDeviceFactory::ThermostatDeviceFactory(QString name): _name(name)
{

}

Device *ThermostatDeviceFactory::createDevice()
{
    return new Thermostat(_name);
}

