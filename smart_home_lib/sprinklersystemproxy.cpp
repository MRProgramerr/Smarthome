#include "sprinklersystemproxy.h"


SprinklerSystemProxy::SprinklerSystemProxy(QString name)
{

    SprinklerDeviceFactory sdf(name);

    _sprinklerSystem = dynamic_cast<SprinklerSystem*>(_deviceFactory->createDevice(&sdf));

}

Device *SprinklerSystemProxy::realDevice()
{
    return _sprinklerSystem;
}

