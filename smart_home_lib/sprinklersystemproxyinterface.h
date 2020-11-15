#ifndef SPRINKLERSYSTEMPROXYINTERFACE_H
#define SPRINKLERSYSTEMPROXYINTERFACE_H

#include "proxyinterface.h"
#include <QObject>
#include "measurementtemplate.h"

/**
 * @brief The SprinklerSystemProxyInterface class
 * An interface which defines the various functions
 * Used for the proxy pattern
 */

class SprinklerSystemProxyInterface : public ProxyInterface
{
public:

    virtual ~SprinklerSystemProxyInterface(){};

    virtual int getUpdateFrequency() =0;
    virtual void setUpdateFrequency(int value) =0;

    virtual double getWaterConsumptionPerInterval() =0 ;
    virtual void setWaterConsumptionPerInterval(double value) =0;

    virtual double getlifetimeConsumption()=0;
    virtual void setlifetimeConsumption(double value)=0;

    virtual bool getIsOn() =0;
    virtual void turnOn()=0;

    virtual void turnOff()=0;

    virtual void schedule(QTime delay, QTime duration)=0;

    virtual void setcurrrentState(std::string state)=0;
    virtual std::vector<MeasurementTemplate<QTime>*> currentState()=0;
    virtual std::vector<MeasurementTemplate<double>*> waterUsage()=0;
    virtual double waterConsumptionPerCycle(QDateTime on, QDateTime off) = 0;

};

#endif // SPRINKLERSYSTEMPROXYINTERFACE_H
