#include "lightswitchfactory.h"

#include "lightswitch.h"

LightSwitchFactory::LightSwitchFactory(QString name) : _name(name)
{

}

Device LightSwitchFactory::createDevice()
{

    LightSwitch ls(_name);
    return ls;

}
