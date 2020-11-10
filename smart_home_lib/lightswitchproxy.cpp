#include "lightswitchproxy.h"

LightSwitchProxy::LightSwitchProxy(QString name)
{

    LightSwitchDeviceFactory ldf(name);

     _lSwitch =  dynamic_cast<LightSwitch*>(_deviceFactory->createDevice(&ldf));


}

void LightSwitchProxy::turnOn()
{
    _lSwitch->turnOn();
}

void LightSwitchProxy::turnOff()
{
    _lSwitch->turnOff();
}

void LightSwitchProxy::brighten()
{
    _lSwitch->brighten();
}

void LightSwitchProxy::dim()
{
    _lSwitch->dim();
}

bool LightSwitchProxy::getIsOn()
{
    return _lSwitch->getIsOn();
}

std::vector<MeasurementTemplate<bool> > LightSwitchProxy::currentState()
{
    return _lSwitch->currentState();
}

