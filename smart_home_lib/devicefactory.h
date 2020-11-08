#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include "device.h"
#include "deviceabstractfactory.h"

class DeviceFactory
{
public:
    DeviceFactory();

    Device* createDevice(DeviceAbstractFactory* daf);


};

#endif // DEVICEFACTORY_H
