#ifndef LIGHTSWITCHDEVICEFACTORY_H
#define LIGHTSWITCHDEVICEFACTORY_H

#include "deviceabstractfactory.h"


class LightSwitchDeviceFactory : public DeviceAbstractFactory
{

public:
    LightSwitchDeviceFactory(QString name);

    Device *createDevice();

private:
    QString _name;
};

#endif // LIGHTSWITCHDEVICEFACTORY_H
