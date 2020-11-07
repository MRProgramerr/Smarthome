#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"
#include "measurement.h"
#include <QObject>

class Thermostat : public Device
{
    Q_OBJECT
public:
    Thermostat();
    Measurement<double> lastMeasurement();
    Measurement<std::vector<double>> last5Measurement();
    Measurement<double> setpoint();
    int currentState();
    void warmer(double amount);
    void cooler(double amount);

};

#endif // THERMOSTAT_H
