#ifndef THERMOSTATPROXY_H
#define THERMOSTATPROXY_H
#include <QString>

#include "thermostatproxyinterface.h"
#include "thermostatdevicefactory.h"
#include "devicefactory.h"
#include "thermostat.h"

class ThermostatProxy : public ThermostatProxyInterface
{

public:
    ThermostatProxy(QString name );

    int getUpdateFrequency() override;

    void setUpdateFrequency(int value)override;

    std::string unitofMeasure() override;

    void setUnitofMeasure(std::string unitofMeasure)override;

    void setStartingTemperature(double starttemp)override;

    double getStartingTemperature()override;

    AbstractMeasurement *lastMeasurement()override;

    void setlastMeasurement(double value)override;

    void storelastMeasurements(double addvalue)override;

    void setthesetpoint(double temp)override;

    AbstractMeasurement *last5Measurement()override;

    AbstractMeasurement *setpoint()override;

    std::string currentState()override;

    void warmer(double amount)override;

    void cooler(double amount)override;

    double randomDouble()override;

    ~ThermostatProxy();
private:

    DeviceFactory* _deviceFactory;

    Thermostat* _thermoStat;

};

#endif // THERMOSTATPROXY_H
