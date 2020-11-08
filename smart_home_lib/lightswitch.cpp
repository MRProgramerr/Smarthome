#include "lightswitch.h"


LightSwitch::LightSwitch(QString name) : Device(name)
{

}

bool LightSwitch::getIsOn()
{
    return _isOn;
}

void LightSwitch::turnOn()
{
    _isOn = true;
    emit reportChange("The light switch has turned On");
}


void LightSwitch::turnOff( )
{
    _isOn = false;
    emit reportChange("The light switch has turned Off");
}

int LightSwitch::getBrightnessLevel()
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


void LightSwitch::receiveChange(QString change){

    qDebug() << change ;
}

