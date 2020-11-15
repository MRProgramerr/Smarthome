#include "sprinklersystemproxy.h"
#include "sprinklersystemproxy.h"

SprinklerSystemProxy::SprinklerSystemProxy(QObject *parent) : QObject(parent)
{

}


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
    std::string signal = "Water consumption per interval set to: " + std::to_string(value);
    emit send(QString::fromStdString(signal));
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
    if(_sprinklerSystem->getIsOn()){

        emit send("I am already turned on");

    }else{
        _sprinklerSystem->turnOn();
        emit send("I have been turned on");
    }
}

void SprinklerSystemProxy::turnOff()
{
    if(_sprinklerSystem->getIsOn()){

        _sprinklerSystem->turnOff();
        emit send("I have been turned off");

    }else{

        emit send("I am already turned off");
    }
}

void SprinklerSystemProxy::schedule(QTime delay, QTime duration){

    std::string signal = "I have been scheduled to turn on after " + delay.toString().toStdString() + " seconds";
    emit send(QString::fromStdString(signal));
    _sprinklerSystem->schedule(delay,duration);
}

void SprinklerSystemProxy::setcurrrentState(std::string state)
{

    _sprinklerSystem->setcurrrentState(state);
}
std::vector<MeasurementTemplate<QTime>*> SprinklerSystemProxy::currentState()
{
    if(_sprinklerSystem->getIsOn()){
        emit send("My state : I am turned on and watering your plants");

    }else{
        emit send("My state: I am turned off and waiting for you to turn me on");
    }
    return _sprinklerSystem->currentState();
}
std::vector<MeasurementTemplate<double>*> SprinklerSystemProxy::waterUsage()
{
    return _sprinklerSystem->waterUsage();
}
Device *SprinklerSystemProxy::realDevice()
{
    return _sprinklerSystem;
}

void SprinklerSystemProxy::setPortController(QString port)
{
    _sprinklerSystem->setPortNumberController(port);
}

void SprinklerSystemProxy::setIPAddressController(QString IPAddress)
{
    _sprinklerSystem->setIPAddressController(IPAddress);
}

double SprinklerSystemProxy::waterConsumptionPerCycle(QDateTime on, QDateTime off)
{
    return _sprinklerSystem->waterConsumptionPerCycle(on,  off);
}
