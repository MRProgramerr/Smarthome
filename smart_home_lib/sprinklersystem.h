#ifndef SPRINKLERSYSTEM_H
#define SPRINKLERSYSTEM_H

#include "device.h"
#include <QObject>

class SprinklerSystem : public Device
{
    Q_OBJECT
public:
    SprinklerSystem();
};

#endif // SPRINKLERSYSTEM_H
