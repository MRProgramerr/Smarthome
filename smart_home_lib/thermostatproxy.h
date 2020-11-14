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

    MeasurementTemplate<double> *lastMeasurement()override;

    void setlastMeasurement(double value)override;

    void storelastMeasurements(double addvalue)override;

    void setthesetpoint(double temp)override;

    MeasurementTemplate<std::vector<double>> *last5Measurement()override;

    MeasurementTemplate<double> *setpoint()override;

    void setcurrentstate(std::string state) override;
    MeasurementTemplate<double> *currentState()override;

    void warmer(double amount)override;

    void cooler(double amount)override;

    double randomDouble()override;
    void update() override;


    void setPortController(QString port);
    void setIPAddressController(QString IPAddress) ;

private:

    DeviceFactory* _deviceFactory = nullptr;

    Thermostat* _thermoStat = nullptr;


    // ProxyInterface interface
public:
    Device *realDevice() override;
};

#endif // THERMOSTATPROXY_H
