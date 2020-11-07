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

std::vector<Measurement> LightSwitch::currentState()
{

    // Placeholder
    std::vector<Measurement> s;
    // Logic here

    return s;
}

void LightSwitch::receiveChange(QString change){

    qDebug() << change ;
}


void LightSwitch::menuLightSwitch(){

    int _userInput;

    qDebug() << endl << "-----------------Light Switch---------------" << endl;

    qDebug() << "Press 1 to Turn On" << endl << "Press 2 to Turn Off" << endl
             << "Press 3 to Dim Light" << endl << "Press 4 to Brigthen light" <<endl;


    std::cin >> _userInput;
    std::cin.ignore();
    std::cout << _userInput << std::endl;


    qDebug() << "--------------------------------------------" << endl;


}
