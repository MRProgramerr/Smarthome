#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H
#include "device.h"
#include "deviceabstractfactory.h"

/**
 * @brief The DeviceFactory class
 * Uses abstract device factories to create
 * concrete devices
 */


class DeviceFactory
{
public:

    DeviceFactory();

    /**
     * @brief createDevice
     * @param daf : The device abstract factory required to create the approproiate device
     * @return a device object
     */
    Device* createDevice(DeviceAbstractFactory* daf);


};

#endif // DEVICEFACTORY_H
