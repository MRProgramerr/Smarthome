#ifndef THERMOSTATPROXYINTERFACE_H
#define THERMOSTATPROXYINTERFACE_H
#include "proxyinterface.h"
#include "measurementtemplate.h"

class ThermostatProxyInterface : public ProxyInterface
{
public:
    virtual ~ThermostatProxyInterface(){};

    virtual int getUpdateFrequency()  = 0;
    virtual void setUpdateFrequency(int value) =0;
    virtual std::string unitofMeasure()=0;
    virtual void setUnitofMeasure(std::string unitofMeasure) =0;
    virtual void setStartingTemperature(double starttemp) =0;
    virtual double getStartingTemperature() =0;
    virtual AbstractMeasurement *lastMeasurement() =0;
    virtual void setlastMeasurement(double value)=0;
    virtual void storelastMeasurements(double addvalue)=0;
    virtual void setthesetpoint(double temp)=0;
    virtual AbstractMeasurement *last5Measurement()=0;
    virtual AbstractMeasurement *setpoint()=0;
    virtual std::string currentState()=0;
    virtual void warmer(double amount)=0;
    virtual void cooler(double amount)=0;
    virtual double randomDouble()=0;



};

#endif // THERMOSTATPROXYINTERFACE_H
