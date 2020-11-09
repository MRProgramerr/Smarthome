#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"

#include <QObject>

class Thermostat : public Device
{
    Q_OBJECT
public:

    Thermostat(QString name);
    Thermostat(QString name, QString port,QString IP_address, int updatefrequency, char UoM, double starttemperature);

//    template<>
//    Measurement<double> lastMeasurement();
//    void setlastMeasurement(double value);
//    void storelastMeasurements(double addvalue);
//    void setcurrentdesiredtemperature(double temp);
//    Measurement<std::vector<double>> last5Measurement();
//    double setpoint();
//    int currentState();
//    void warmer(double amount);
//    void cooler(double amount);

private:
    QString Name;
    QString IP_Address;
    QString Port;
    int UpdateFrequency;
    double StartTemperature;
    char UoM;
    std::vector<double> last5values;
    double lastvalue;
    double Temp;
};

#endif // THERMOSTAT_H
