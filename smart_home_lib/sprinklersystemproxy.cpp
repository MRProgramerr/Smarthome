#include "sprinklersystemproxy.h"


SprinklerSystemProxy::SprinklerSystemProxy(QString name)
{

    SprinklerDeviceFactory sdf(name);

    _sprinklerSystem = dynamic_cast<SprinklerSystem*>(_deviceFactory->createDevice(&sdf));

}


int SprinklerSystemProxy::getUpdateFrequency(){
    return _sprinklerSystem->getUpdateFrequency();
}
void SprinklerSystemProxy::setUpdateFrequency(int value)
{
    _sprinklerSystem->setUpdateFrequency(value);
}

double SprinklerSystemProxy::getWaterConsumptionPerInterval()
{
    return _sprinklerSystem->getWaterConsumptionPerInterval();
}
void SprinklerSystemProxy::setWaterConsumptionPerInterval(double value)
{
    _sprinklerSystem->setWaterConsumptionPerInterval(value);
}

double SprinklerSystemProxy::getlifetimeConsumption()
{
   return _sprinklerSystem->getlifetimeConsumption();
}
void SprinklerSystemProxy::setlifetimeConsumption(double value)
{
    _sprinklerSystem->setlifetimeConsumption(value);
}

bool SprinklerSystemProxy::getIsOn()
{
    return _sprinklerSystem->getIsOn();
}
void SprinklerSystemProxy::turnOn()
{
    _sprinklerSystem->turnOn();
}

void SprinklerSystemProxy::turnOff()
{
    _sprinklerSystem->turnOff();
}

void SprinklerSystemProxy::schedule(QTime delay, QTime duration)
{
    _sprinklerSystem->schedule(delay,duration);
}

void SprinklerSystemProxy::setcurrrentState(std::string state)
{
    _sprinklerSystem->setcurrrentState(state);
}
std::vector<MeasurementTemplate<QTime>*> SprinklerSystemProxy::currentState()
{
    return _sprinklerSystem->currentState();
}
std::vector<MeasurementTemplate<double>*> SprinklerSystemProxy::waterUsage()
{
    return _sprinklerSystem->waterUsage();
}
