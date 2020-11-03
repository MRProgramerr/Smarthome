#include "lightswitch.h"

LightSwitch::LightSwitch(QString name) : Device(name)
{

}

bool LightSwitch::getIsOn() const
{
    return _isOn;
}

void LightSwitch::turnOn(bool value)
{
    _isOn = value;
}

bool LightSwitch::getIsOff() const
{
    return _isOff;
}

void LightSwitch::turnOff(bool value)
{
    _isOff = value;
}

int LightSwitch::getBrightnessLevel() const
{
    return _brightnessLevel;
}

void LightSwitch::setBrightnessLevel(int value)
{
    _brightnessLevel = value;
}


void LightSwitch::dim(){

    // Ensures that the minimum brightness remains 20
    if(getBrightnessLevel() > 40){
        setBrightnessLevel(getBrightnessLevel()-20);
    }else{
        setBrightnessLevel(20);
    }

}

void LightSwitch::brighten(){

    // Ensures that the max brighness is 100
    if(getBrightnessLevel()+20 > 100){
        setBrightnessLevel(100);
    }else{
        setBrightnessLevel(getBrightnessLevel()+20);
    }

}
