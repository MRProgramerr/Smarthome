#include "sprinklerdevicefactory.h"

#include "sprinklersystem.h"


SprinklerDeviceFactory::SprinklerDeviceFactory(QString name) : _name(name)
{

}

Device *SprinklerDeviceFactory::createDevice()
{
    return new SprinklerSystem(_name);
}
