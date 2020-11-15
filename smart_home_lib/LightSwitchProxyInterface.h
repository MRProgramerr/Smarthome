#ifndef LIGHTSWITCHPROXYINTERFACE_H
#define LIGHTSWITCHPROXYINTERFACE_H

#include <vector>
#include "proxyinterface.h"
#include "measurementtemplate.h"

/**
 * @brief The LightSwitchProxyInterface class
 * An interface which defines the various functions
 * Used for the proxy pattern
 */

class LightSwitchProxyInterface : public ProxyInterface
{
public:

    /**
     * @brief ~LightSwitchProxyInterface
     * The virtual destructor for the light switch proxy interface class
     */
    virtual ~LightSwitchProxyInterface(){};

    /**
     * @brief turnOn : Defines The turning on of the lightswitch
     */
    virtual void turnOn() = 0;

    /**
     * @brief turnOff : Defines The turning off of the lightswitch
     */
    virtual void turnOff() = 0;

    /**
     * @brief brighten: Defines The brightening of the lightswitch
     */
    virtual void brighten() = 0;

    /**
     * @brief dim : defines the dimming of the lightswitch
     */
    virtual void dim() = 0;

    /**
     * @brief getIsOn
     * @return
     */
    virtual bool getIsOn() = 0;


    /**
     * @brief powerStatus : defines the power status of lightswitch
     * @return
     */
    virtual MeasurementTemplate<bool> powerStatus() = 0;

    /**
     * @brief brightnessStatus: defines the brightnessStatus of lightswitch
     * @return
     */
    virtual MeasurementTemplate<int> brightnessStatus() = 0;


    /**
     * @brief realDevice
     * @return the device itself
     */
    virtual Device *realDevice() = 0;
};

#endif // LIGHTSWITCHPROXYINTERFACE_H
