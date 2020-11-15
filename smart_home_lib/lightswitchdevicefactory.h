#ifndef LIGHTSWITCHDEVICEFACTORY_H
#define LIGHTSWITCHDEVICEFACTORY_H

#include "deviceabstractfactory.h"

/**
 * @brief The LightSwitchDeviceFactory class
 * A concrete factory for creating light switch devices
 */

class LightSwitchDeviceFactory : public DeviceAbstractFactory
{

public:

    /**
     * @brief LightSwitchDeviceFactory
     * The constructor for the light switch device factory
     * @param name
     */
    LightSwitchDeviceFactory(QString name);

    /**
     * @brief createDevice
     * @return A lightswitch object
     */
    Device *createDevice();

private:
    QString _name;
};

#endif // LIGHTSWITCHDEVICEFACTORY_H
