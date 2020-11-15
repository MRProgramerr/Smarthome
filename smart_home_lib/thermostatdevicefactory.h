#ifndef THERMOSTATDEVICEFACTORY_H
#define THERMOSTATDEVICEFACTORY_H

#include "deviceabstractfactory.h"

/**
 * @brief The ThermostatDeviceFactory class
 * A concrete factory for creating thermostat devices
 */

class ThermostatDeviceFactory : public DeviceAbstractFactory
{
public:

    /**
     * @brief ThermostatDeviceFactory
     * @param name of the thermostat
     */
    ThermostatDeviceFactory(QString name);

    /**
     * @brief createDevice
     * @return A thermostat object
     */
    Device *createDevice();

private:
    QString _name;
};

#endif // THERMOSTATDEVICEFACTORY_H
