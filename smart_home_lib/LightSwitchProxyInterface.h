
#ifndef LIGHTSWITCHPROXYINTERFACE_H
#define LIGHTSWITCHPROXYINTERFACE_H

#include <vector>
#include "proxyinterface.h"
#include "measurementtemplate.h"

class LightSwitchProxyInterface : public ProxyInterface
{
public:

    virtual ~LightSwitchProxyInterface(){};

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void brighten() = 0;
    virtual void dim() = 0;
    virtual bool getIsOn() = 0;


    virtual std::vector<MeasurementTemplate<bool>> currentState() = 0;
//    virtual std::vector<Measurement<>> currentState() = 0;


    virtual Device *realDevice() = 0;
};

#endif // LIGHTSWITCHPROXYINTERFACE_H
