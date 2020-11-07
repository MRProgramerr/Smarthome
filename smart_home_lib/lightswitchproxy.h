#ifndef LIGHTSWITCHPROXY_H
#define LIGHTSWITCHPROXY_H

#include "lightswitchproxyinterface.h"

class LightSwitchProxy : public LightSwitchProxyInterface
{
public:
    LightSwitchProxy();

    // LightSwitchProxyInterface interface
public:
    void turnOn() override;
    void turnOff() override;
    void brighten() override;
    void dim() override;
    std::vector<Measurement> currentState() override;
};

#endif // LIGHTSWITCHPROXY_H
