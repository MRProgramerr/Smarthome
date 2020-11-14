#ifndef LIGHTSWITCHPROXY_H
#define LIGHTSWITCHPROXY_H

#include "LightSwitchProxyInterface.h"
#include "lightswitch.h"
#include "proxyinterface.h"
#include "lightswitchdevicefactory.h"
#include "devicefactory.h"
#include <QObject>


#include <QObject>

class LightSwitchProxy : public QObject, public LightSwitchProxyInterface
{
    Q_OBJECT
public:
    explicit LightSwitchProxy(QObject *parent = nullptr);
    LightSwitchProxy(QString name);


    /**
         * @brief turnOn
         * An overriden TurnOn Method
         * Calls turnOn method on the real device
         */
        void turnOn() override;

        /**
         * @brief turnOff
         * An overriden TurnOff Method
         * Calls turnOff method on the real device
         */
        void turnOff() override;

        /**
         * @brief brighten
         * Calls brigthen method on the real device
         */
        void brighten() override;

        /**
         * @brief dim
         * Calls dim method on the real device
         */
        void dim() override;

        bool getIsOn() override;

        MeasurementTemplate<bool>  powerStatus() override;

        void setPortController(QString port);
        void setIPAddressController(QString IPAddress) ;

signals:

        void send(QString data);

    private:



        DeviceFactory* _deviceFactory;

        /**
         * @brief _lightSwitch
         *
         */
        LightSwitch* _lSwitch;





        // ProxyInterface interface
    public:
        Device *realDevice() override;

        // LightSwitchProxyInterface interface
    public:
        MeasurementTemplate<int> brightnessStatus() override;
    };

#endif // LIGHTSWITCHPROXY_H
