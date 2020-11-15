#ifndef SPRINKLERSYSTEM_H
#define SPRINKLERSYSTEM_H

#include "device.h"
#include <QObject>
#include <chrono>
#include <thread>
#include <future>
#include <iostream>
#include "measurementtemplate.h"
#include "abstractmeasurement.h"
#include "sprinklersystemproxyinterface.h"



/**
 * @brief The SprinklerSystem class
 * Concrete implementation of the sprinkler device
 * Inherits Abstract Device and the sprinkler proxy
 * interface using multiple inheritance.
 */

class SprinklerSystem : public Device,public SprinklerSystemProxyInterface
{
    Q_OBJECT
public:

    /**
     * @brief SprinklerSystem
     * @param name : name of the sprinkler system
     */
    SprinklerSystem(QString name);

    /**
     * @brief getUpdateFrequency
     * @return The update frequencey for the sprinkler system
     */
    int getUpdateFrequency() ;

    /**
     * @brief setUpdateFrequency
     * The setter function for the update frequencey of the sprinkler system
     * @param value
     */
    void setUpdateFrequency(int value);

    /**
     * @brief getWaterConsumptionPerInterval
     * @return The water consumpiton per interval of the sprinkler system
     */
    double getWaterConsumptionPerInterval() ;

    /**
     * @brief setWaterConsumptionPerInterval
     * The setter function for the water consumpiton per interval of the sprinkler system
     * @param value
     */
    void setWaterConsumptionPerInterval(double value);

    /**
     * @brief getlifetimeConsumption
     * @return The lifetime consumption of the sprinkler system
     */
    double getlifetimeConsumption();
    void setlifetimeConsumption(double value);

    /**
     * @brief getIsOn
     * @return True if sprinkler system turned on else false
     */
    bool getIsOn() ;

    /**
     * @brief turnOn
     * Used to turn on the sprinkler system
     */
    void turnOn();

    /**
     * @brief turnOff
     * Used to turn off the sprinkler system
     */
    void turnOff();

    /**
     * @brief schedule
     * Used to schedule
     * @param delay : The delay after the system is to be turned on
     * @param duration
     */
    void schedule(QTime delay, QTime duration);

    /**
     * @brief setcurrrentState
     * Used to set the current state of the sprinkler system such as
     * scheduled, on, off, etc.
     * @param state
     */
    void setcurrrentState(std::string state);

    /**
     * @brief currentState
     * @return The currentstate of the sprinkler system
     */
    std::vector<MeasurementTemplate<QTime>*> currentState();

    /**
     * @brief waterUsage
     * @return The water consumed by the sprinkler system
     */
    std::vector<MeasurementTemplate<double>*> waterUsage();

    /**
     * @brief realDevice
     * @return The actual device itself
     */
    Device *realDevice();

    /**
     * @brief deviceType
     * @return "Sprinkler System"
     */
    std::string deviceType();

    /**
     * @brief waterConsumptionPerCycle
     * Calculates and returns the water consumed by the device
     * for an on-off cycle.
     * @param on : Time when the device was turned on
     * @param off : Time when the device was turned off
     * @return
     */
    double waterConsumptionPerCycle(QDateTime on, QDateTime off);


private:

    int _updateFrequency = 5;
    double _waterConsumptionPerInterval =  0;
    double totalConsumption;
    bool _isOn  = false;
    QString Name = "";
    QTime Duration;
    QTime Delay;
    std::string thestate = "";
    AbstractMeasurement *am = nullptr;
    std::vector<AbstractMeasurement*> abvector;
    MeasurementTemplate<QTime> *mtstate = nullptr;
    MeasurementTemplate<QTime> *mtstate2 = nullptr;
    MeasurementTemplate<QTime> *mtstate3 = nullptr;
    MeasurementTemplate<double> *mtusage = nullptr;
    MeasurementTemplate<double> *mtusage2 = nullptr;
    std::vector<MeasurementTemplate<QTime>*> mtvectorstate;
    std::vector<MeasurementTemplate<double>*> mtvectorusage;
    QDateTime onStamp;
    QDateTime offStamp;




};

#endif // SPRINKLERSYSTEM_H
