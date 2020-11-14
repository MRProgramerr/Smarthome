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

    if(_lSwitch->getIsOn()){

        emit send("I am already turned on");

    }else{
        _lSwitch->turnOn();
        emit send("I have been turned on");
    }


}

void LightSwitchProxy::turnOff()
{
    if(_lSwitch->getIsOn()){

        _lSwitch->turnOff();
        emit send("I have been turned off");

    }else{

        emit send("I am already turned off");
    }
}

void LightSwitchProxy::brighten()
{
    _lSwitch->brighten();
    std::string signal = "I have been brightened to " + std::to_string(_lSwitch->getBrightnessLevel());
    emit send(QString::fromStdString(signal) );
}

void LightSwitchProxy::dim()
{
    _lSwitch->dim();

    std::string signal = "I have been dimmed to " + std::to_string(_lSwitch->getBrightnessLevel());

    emit send(QString::fromStdString(signal) );
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

void LightSwitchProxy::currentStatus()
{

    std::string signal;

    if(_lSwitch->powerStatus().value().toString().toLower()=="true"){
        signal += "I am turned on";
    }else{
        signal += "I am turned off";
    }

    signal += " and My brightness level is: " + std::to_string(_lSwitch->getBrightnessLevel());
    emit send(QString::fromStdString(signal));
}



