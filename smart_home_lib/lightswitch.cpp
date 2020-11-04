#include "lightswitch.h"

LightSwitch::LightSwitch(QString name) : Device(name)
{

}

bool LightSwitch::getIsOn()
{
    return _isOn;
}

void LightSwitch::turnOn(bool value)
{
    _isOn = value;
}

bool LightSwitch::getIsOff()
{
    return _isOff;
    emit reportChange("The light switch has turned Off");
}

void LightSwitch::turnOff(bool value)
{
    _isOff = value;
    emit reportChange("The light switch has turned On");
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


void LightSwitch::menuLightSwitch(){

    qDebug() << endl << "-----------------Light Switch---------------" << endl;

    qDebug() << "Press 1 to Turn On" << endl << "Press 2 to Turn Off" << endl
             << "Press 3 to Dim Light" << endl << "Press 4 to Brigthen light" <<endl;

    std::cout << "Hello";


    qDebug() << "--------------------------------------------" << endl;


}
