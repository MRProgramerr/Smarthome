#ifndef SPRINKLERSYSTEMPROXY_H
#define SPRINKLERSYSTEMPROXY_H

#include <QString>
#include "sprinklersystemproxyinterface.h"
#include "devicefactory.h"
#include "sprinklersystem.h"
#include "sprinklerdevicefactory.h"


class SprinklerSystemProxy : public SprinklerSystemProxyInterface
{
public:
    SprinklerSystemProxy(QString name);

    // Required functions overrides here
private:

     DeviceFactory* _deviceFactory;

     SprinklerSystem* _sprinklerSystem;

};

#endif // SPRINKLERSYSTEMPROXY_H
