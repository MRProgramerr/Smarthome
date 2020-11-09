#ifndef LIGHTSWITCHPROXY_H
#define LIGHTSWITCHPROXY_H

#include "LightSwitchProxyInterface.h"
#include "lightswitch.h"
#include "proxyinterface.h"
#include "lightswitchdevicefactory.h"
#include "devicefactory.h"

/**
 * @brief The LightSwitchProxy class
 * @details This is the proxy for the lightswitch
 * This class will contain an instantiation of the real
 * device and will delegate the functions calls to it.
 */

class LightSwitchProxy : public LightSwitchProxyInterface, public ProxyInterface
{
public:

    /**
     * @brief LightSwitchProxy
     * @param name : The name of the lightswitch
     * The constructor for the light Switch proxy
     * The instantiation of the real device
     * is done in the constructor.
     */
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

// std::vector<Measurement> currentState() override;


private:

    /**
     * @brief _lightSwitch
     *
     */

    DeviceFactory* _deviceFactory;

    LightSwitch* _lSwitch;


};

#endif // LIGHTSWITCHPROXY_H
