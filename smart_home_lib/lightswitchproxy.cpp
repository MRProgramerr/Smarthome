#include "lightswitchproxy.h"

LightSwitchProxy::LightSwitchProxy(QString name) : _lightSwitch(name)
{

}

void LightSwitchProxy::turnOn()
{
    _lightSwitch.turnOn();
}

void LightSwitchProxy::turnOff()
{
    _lightSwitch.turnOff();
}

void LightSwitchProxy::brighten()
{
    _lightSwitch.brighten();
}

void LightSwitchProxy::dim()
{
    _lightSwitch.dim();
}

bool LightSwitchProxy::getIsOn()
{
    return _lightSwitch.getIsOn();
}

