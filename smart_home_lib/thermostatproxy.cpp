#include "thermostatproxy.h"

ThermostatProxy::ThermostatProxy(QObject *parent) : QObject(parent)
{

}
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
    std::string signal = "Update Frequency set to " + std::to_string(value);
    emit send(QString::fromStdString(signal));

}

std::string ThermostatProxy::unitofMeasure()
{
    return _thermoStat->unitofMeasure();
}

void ThermostatProxy::setUnitofMeasure(std::string unitofMeasure)
{
     _thermoStat->setUnitofMeasure(unitofMeasure);
     std::string signal = "Unit of measure set to " + unitofMeasure;
     emit send(QString::fromStdString(signal));
}

void ThermostatProxy::setStartingTemperature(double starttemp)
{
    _thermoStat->setStartingTemperature(starttemp);
    std::string signal = "Starting Temp set to " + std::to_string(starttemp);
    emit send(QString::fromStdString(signal));
}

double ThermostatProxy::getStartingTemperature()
{
    return _thermoStat->getStartingTemperature();
}

MeasurementTemplate<double> *ThermostatProxy::lastMeasurement()
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

MeasurementTemplate<std::vector<double>> *ThermostatProxy::last5Measurement()
{
    return _thermoStat->last5Measurement();
}

MeasurementTemplate<double> *ThermostatProxy::setpoint()
{
    return _thermoStat->setpoint();
}

void ThermostatProxy::setcurrentstate(std::string state)
{
    return _thermoStat->setcurrentstate(state);
}

MeasurementTemplate<double> *ThermostatProxy::currentState()
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

void ThermostatProxy::update()
{
    return _thermoStat->update();
}

void ThermostatProxy::setPortController(QString port)
{
    _thermoStat->setPortNumberController(port);
}

void ThermostatProxy::setIPAddressController(QString IPAddress)
{
    _thermoStat->setIPAddressController(IPAddress);
}

Device *ThermostatProxy::realDevice()
{
    return _thermoStat;
}


