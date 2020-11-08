#ifndef DEVICEABSTRACTFACTORY_H
#define DEVICEABSTRACTFACTORY_H

#include "device.h"

class DeviceAbstractFactory
{
public:
    virtual  ~DeviceAbstractFactory(){};
    virtual Device* createDevice() = 0;
};

#endif // DEVICEABSTRACTFACTORY_H
