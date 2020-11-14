#ifndef SPRINKLERSYSTEMPROXY_H
#define SPRINKLERSYSTEMPROXY_H

#include <QString>
#include "sprinklersystemproxyinterface.h"
#include "devicefactory.h"
#include "sprinklersystem.h"
#include "sprinklerdevicefactory.h"

#include <QObject>

class SprinklerSystemProxy : public QObject, public SprinklerSystemProxyInterface
{
    Q_OBJECT
public:
    explicit SprinklerSystemProxy(QObject *parent = nullptr);
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
    Device *realDevice() override;

    void setPortController(QString port);
    void setIPAddressController(QString IPAddress) ;

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
