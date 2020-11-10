#include "lightswitch.h"
#include "measurementtemplate.h"



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
    emit reportChange("The Device has Turned On");
}


void LightSwitch::turnOff( )
{
    _isOn = false;
     emit reportChange("The Device has Turned Off");

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
         emit reportChange(&"The Brightness has reduced to:" [ this->_brightnessLevel]);
    }else{
        setBrightnessLevel(20);
        emit reportChange("The brightness has been set to the minumum 20 units");
    }



}

void LightSwitch::brighten(){

    std::cout << "In here" << std::endl;

    // Ensures that the max brighness is 100
    if(getBrightnessLevel()+20 > 100){
        setBrightnessLevel(100);
        emit reportChange(&"The Brightness has increased to:" [ this->_brightnessLevel]);
    }else{
        setBrightnessLevel(getBrightnessLevel()+20);
        emit reportChange("The brightness has been set to the maximum 100 units");

    }

}

std::vector<MeasurementTemplate<bool>> LightSwitch::currentState()
{

    MeasurementTemplate<bool> powerStatus("LightSwitch","Power","");
    powerStatus.setValue(_isOn);


    _stateVector.push_back(powerStatus);

    return _stateVector;



}
void LightSwitch::receiveChange(QString change){

    qDebug() << "The Device replied:" << change ;
}

Device *LightSwitch::realDevice()
{
    return this;
}

