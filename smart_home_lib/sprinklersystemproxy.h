#ifndef SPRINKLERSYSTEMPROXY_H
#define SPRINKLERSYSTEMPROXY_H

#include <QString>
#include "sprinklersystemproxyinterface.h"
#include "devicefactory.h"
#include "sprinklersystem.h"
#include "sprinklerdevicefactory.h"


class SprinklerSystemProxy : public SprinklerSystemProxyInterface
{
public:
    SprinklerSystemProxy(QString name);


    int getUpdateFrequency() override;
    void setUpdateFrequency(int value)override;

    double getWaterConsumptionPerInterval() override;
    void setWaterConsumptionPerInterval(double value)override;

    double getlifetimeConsumption()override;
    void setlifetimeConsumption(double value)override;

    bool getIsOn()override ;
    void turnOn()override;

    void turnOff()override;

    void schedule(QTime delay, QTime duration)override;

    void setcurrrentState(std::string state)override;
    std::vector<MeasurementTemplate<QTime>*> currentState()override;
    std::vector<MeasurementTemplate<double>*> waterUsage()override;
private:

     DeviceFactory* _deviceFactory = nullptr;

     SprinklerSystem* _sprinklerSystem = nullptr;

};

#endif // SPRINKLERSYSTEMPROXY_H
