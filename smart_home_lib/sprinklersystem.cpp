#include "sprinklersystem.h"

SprinklerSystem::SprinklerSystem(QString name) : Device(name)
{

}

int SprinklerSystem::getUpdateFrequency()
{
    return _updateFrequency;
}

void SprinklerSystem::setUpdateFrequency(int value)
{
    _updateFrequency = value;
}

int SprinklerSystem::getWaterConsumptionPerInterval()
{
    return _waterConsumptionPerInterval;
}

void SprinklerSystem::setWaterConsumptionPerInterval(int value)
{
    _waterConsumptionPerInterval = value;
}

bool SprinklerSystem::getIsOn()
{
    return _isOn;
}

void SprinklerSystem::turnOn()
{
    _isOn = true;
    std::cout << "Turned on"<< std::endl;
}


void SprinklerSystem::turnOff( )
{
    _isOn = false;
     std::cout << "Turned off"<< std::endl;
}

void SprinklerSystem::schedule(int delay, int duration)
{


        std::async(std::launch::async, [=] () {

            std::this_thread::sleep_for(std::chrono::seconds{delay});

            this->turnOn();
        } );

        std::this_thread::sleep_for( std::chrono::seconds{2});
           std::cout << "Finished" << std::endl;



}
