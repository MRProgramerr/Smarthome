#ifndef DEVICEABSTRACTFACTORY_H
#define DEVICEABSTRACTFACTORY_H
#include "device.h"

/**
 * @brief The DeviceAbstractFactory class
 * The absract device factory class used for the
 * abstract factory pattern to create devices.
 */

class DeviceAbstractFactory
{
public:

    /**
     * @brief ~DeviceAbstractFactory
     * The virtual destructor for the device abstract factory
     */
    virtual  ~DeviceAbstractFactory(){};

    /**
     * @brief createDevice
     * This methods creates a concrete device and is overriden
     * at appropriate levels
     * @return
     */
    virtual Device* createDevice() = 0;
};

#endif // DEVICEABSTRACTFACTORY_H
