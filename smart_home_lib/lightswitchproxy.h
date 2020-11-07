#ifndef LIGHTSWITCHPROXY_H
#define LIGHTSWITCHPROXY_H

#include "lightswitchproxyinterface.h"
#include "lightswitch.h"

class LightSwitchProxy : public LightSwitchProxyInterface
{
public:

    LightSwitchProxy(QString name);
    void turnOn() override;
    void turnOff() override;
    void brighten() override;
    void dim() override;
//    std::vector<Measurement> currentState() override;


private:

    LightSwitch _lightSwitch;


};

#endif // LIGHTSWITCHPROXY_H
