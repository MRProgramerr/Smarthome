#ifndef SPRINKLERDEVICEFACTORY_H
#define SPRINKLERDEVICEFACTORY_H
#include "deviceabstractfactory.h"

class SprinklerDeviceFactory : public DeviceAbstractFactory
{
public:
      SprinklerDeviceFactory(QString name);

      Device *createDevice();

private:
      QString _name;

};

#endif // SPRINKLERDEVICEFACTORY_H
