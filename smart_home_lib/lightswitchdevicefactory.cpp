#include "lightswitchdevicefactory.h"
#include "device.h"
#include "lightswitch.h"

LightSwitchDeviceFactory::LightSwitchDeviceFactory(QString name) : _name(name)
{

}

Device *LightSwitchDeviceFactory::createDevice()
{
    return new LightSwitch(_name);
}
