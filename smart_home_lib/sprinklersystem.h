#ifndef SPRINKLERSYSTEM_H
#define SPRINKLERSYSTEM_H

#include "device.h"
#include <QObject>
#include <chrono>
#include <thread>
#include <future>
#include <iostream>

class SprinklerSystem : public Device
{
    Q_OBJECT
public:

    SprinklerSystem(QString name);


    int getUpdateFrequency() ;
    void setUpdateFrequency(int value);

    int getWaterConsumptionPerInterval() ;
    void setWaterConsumptionPerInterval(int value);

    bool getIsOn() ;
    void turnOn();

    void turnOff();

    void schedule(int delay,int duration);




private:

    int _updateFrequency = 5;
    int _waterConsumptionPerInterval =  0;
    bool _isOn  = false;



};

#endif // SPRINKLERSYSTEM_H
