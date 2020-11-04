#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"

#include <QObject>

class Thermostat : public Device
{
    Q_OBJECT
public:
    Thermostat();
};

#endif // THERMOSTAT_H
