#include "lightswitchproxy.h"

LightSwitchProxy::LightSwitchProxy(QObject *parent) : QObject(parent)
{

}
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
    emit send("Brightned");
}

void LightSwitchProxy::dim()
{
    _lSwitch->dim();
}

bool LightSwitchProxy::getIsOn()
{
    return _lSwitch->getIsOn();
}

MeasurementTemplate<bool>  LightSwitchProxy::powerStatus()
{
    return _lSwitch->powerStatus();
}

void LightSwitchProxy::setPortController(QString port)
{
    _lSwitch->setPortNumberController(port);
}


void LightSwitchProxy::setIPAddressController(QString IPAddress)
{
    _lSwitch->setIPAddressController(IPAddress);
}

Device *LightSwitchProxy::realDevice()
{
    return _lSwitch;
}

MeasurementTemplate<int> LightSwitchProxy::brightnessStatus()
{
    return _lSwitch->brightnessStatus();
}
