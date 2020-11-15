#ifndef LIGHTSWITCHPROXY_H
#define LIGHTSWITCHPROXY_H

#include "LightSwitchProxyInterface.h"
#include "lightswitch.h"
#include "proxyinterface.h"
#include "lightswitchdevicefactory.h"
#include "devicefactory.h"
#include <QObject>
#include <QObject>

/**
 * @brief The LightSwitchProxy class
 * A proxy for the light switch device
 */

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


        /**
         * @brief getIsOn
         * @return On if power of light is on
         */
        bool getIsOn() override;

        /**
         * @brief powerStatus
         * Returns whether the light switch
         * is on or off as a  measurement object
         * @return
         */
        MeasurementTemplate<bool>  powerStatus() override;

        /**
         * @brief setPortController
         * Setter for the port number
         * @param port
         */
        void setPortController(QString port);

        /**
         * @brief setIPAddressController
         * setter for the IP address
         * @param IPAddress
         */
        void setIPAddressController(QString IPAddress) ;

        /**
         * @brief realDevice
         * This function is used to retrieve a real
         * device from the proxy
         * @return
         */
        Device *realDevice() override;

        /**
         * @brief brightnessStatus
         * Returns the brigthness status of the light
         * @return
         */
        MeasurementTemplate<int> brightnessStatus() override;

        /**
         * @brief currentStatus
         * Returns both power and brightness status
         * of a lightswitch
         */
        void currentStatus() ;

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
        DeviceFactory* _deviceFactory;

        /**
         * @brief _lightSwitch
         *
         */
        LightSwitch* _lSwitch;



    };

#endif // LIGHTSWITCHPROXY_H
