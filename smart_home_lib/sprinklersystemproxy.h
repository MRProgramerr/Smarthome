#ifndef SPRINKLERSYSTEMPROXY_H
#define SPRINKLERSYSTEMPROXY_H

#include <QString>
#include "sprinklersystemproxyinterface.h"
#include "devicefactory.h"
#include "sprinklersystem.h"
#include "sprinklerdevicefactory.h"

#include <QObject>

/**
 * @brief The SprinklerSystemProxy class
 * A proxy for the sprinkler system device
 */

class SprinklerSystemProxy : public QObject, public SprinklerSystemProxyInterface
{
    Q_OBJECT
public:
    explicit SprinklerSystemProxy(QObject *parent = nullptr);

    /**
     * @brief SprinklerSystemProxy
     * @param name of the proxy
     */
    SprinklerSystemProxy(QString name);

    /**
     * @brief getUpdateFrequency
     * Calls getUpdateFrequency on the sprinkler device
     * @return
     */
    int getUpdateFrequency() override;

    /**
     * @brief setUpdateFrequency
     * @param value
     * Calls setUpdateFrequency on the sprinkler device
     */
    void setUpdateFrequency(int value)override;

    /**
     * @brief getWaterConsumptionPerInterval
     * Calls getWaterConsumptionPerInterval on the sprinkler device
     * @return
     */
    double getWaterConsumptionPerInterval() override;

    /**
     * @brief setWaterConsumptionPerInterval
     * Calls setWaterConsumptionPerInterval on the sprinkler device
     * @param value
     */
    void setWaterConsumptionPerInterval(double value)override;

    /**
     * @brief getlifetimeConsumption
     * .Calls getlifetimeConsumption on the sprinkler device
     * @return
     */
    double getlifetimeConsumption()override;

    /**
     * @brief setlifetimeConsumption
     * Calls setlifetimeConsumption on the sprinkler device
     * @param value
     */
    void setlifetimeConsumption(double value)override;

    /**
     * @brief getIsOn
     * Calls getIsOn on the sprinkler device
     * @return
     */
    bool getIsOn()override ;

    /**
     * @brief turnOn
     * Calls turnOn on the sprinkler device
     */
    void turnOn()override;

    /**
     * @brief turnOff
     * Calls turnOff on the sprinkler device
     */
    void turnOff()override;

    /**
     * @brief schedule
     * @param delay
     * @param duration
     * Calls schedule on the sprinkler device
     */
    void schedule(QTime delay, QTime duration)override;

    /**
     * @brief setcurrrentState
     * @param state
     * Calls setcurrrentState on the sprinkler device
     */
    void setcurrrentState(std::string state)override;

    /**
     * @brief currentState
     * @return
     * Calls currentState on the sprinkler device
     */
    std::vector<MeasurementTemplate<QTime>*> currentState()override;

    /**
     * @brief waterUsage
     * @return
     * Calls waterUsage on the sprinkler device
     */
    std::vector<MeasurementTemplate<double>*> waterUsage()override;

    /**
     * @brief realDevice
     * @return
     * Calls realDevice on the sprinkler device
     */
    Device *realDevice() override;

    /**
     * @brief setPortController
     * sets the port number on the real device
     * @param port
     */
    void setPortController(QString port);

    /**
     * @brief setIPAddressController
     * sets the ip address of the real device
     * @param IPAddress
     */
    void setIPAddressController(QString IPAddress) ;

    /**
     * @brief waterConsumptionPerCycle
     * calls the waterConsumptionPerCycle on the real device
     * @param on
     * @param off
     * @return
     */
    double waterConsumptionPerCycle(QDateTime on, QDateTime off) override;

signals:

    /**
     * @brief send
     * This is a QT Signal
     * which sends important data
     * to be recieved by main menu slot
     * @param data
     */
    void send(QString data);

private:

    DeviceFactory* _deviceFactory = nullptr;

    SprinklerSystem* _sprinklerSystem = nullptr;

};


#endif // SPRINKLERSYSTEMPROXY_H
