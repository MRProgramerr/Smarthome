#include "thermostatproxy.h"

ThermostatProxy::ThermostatProxy(QString name)
{

    ThermostatDeviceFactory tdf(name);

    _thermoStat = dynamic_cast<Thermostat*>(_deviceFactory->createDevice(&tdf));

}

int ThermostatProxy::getUpdateFrequency()
{
    return _thermoStat->getUpdateFrequency();
}

void ThermostatProxy::setUpdateFrequency(int value)
{
    _thermoStat->setUpdateFrequency(value);
}

std::string ThermostatProxy::unitofMeasure()
{
    return _thermoStat->unitofMeasure();
}

void ThermostatProxy::setUnitofMeasure(std::string unitofMeasure)
{
     _thermoStat->setUnitofMeasure(unitofMeasure);
}

void ThermostatProxy::setStartingTemperature(double starttemp)
{
    _thermoStat->setStartingTemperature(starttemp);
}

double ThermostatProxy::getStartingTemperature()
{
    return _thermoStat->getStartingTemperature();
}

AbstractMeasurement *ThermostatProxy::lastMeasurement()
{
    return _thermoStat->lastMeasurement();
}

void ThermostatProxy::setlastMeasurement(double value)
{
    _thermoStat->setlastMeasurement(value);
}

void ThermostatProxy::storelastMeasurements(double addvalue)
{
    _thermoStat->storelastMeasurements(addvalue);
}

void ThermostatProxy::setthesetpoint(double temp)
{
    _thermoStat->setthesetpoint(temp);
}

AbstractMeasurement *ThermostatProxy::last5Measurement()
{
    return _thermoStat->last5Measurement();
}

AbstractMeasurement *ThermostatProxy::setpoint()
{
    return _thermoStat->setpoint();
}

std::string ThermostatProxy::currentState()
{
    return _thermoStat->currentState();
}

void ThermostatProxy::warmer(double amount)
{
    _thermoStat->warmer(amount);
}

void ThermostatProxy::cooler(double amount)
{
    _thermoStat->cooler(amount);
}

double ThermostatProxy::randomDouble()
{
    return _thermoStat->randomDouble();
}
