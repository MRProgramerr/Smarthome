#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"
#include "abstractmeasurement.h"
#include "measurementtemplate.h"
#include <QObject>
#include <random>
#include <thermostatproxyinterface.h>

class Thermostat : public Device, public ThermostatProxyInterface
{
    Q_OBJECT
public:

    Thermostat(QString name);
    int getUpdateFrequency() ;
    void setUpdateFrequency(int value);
    std::string unitofMeasure() ;
    void setUnitofMeasure(std::string unitofMeasure);
    void setStartingTemperature(double starttemp);
    double getStartingTemperature();
    AbstractMeasurement *lastMeasurement();
    void setlastMeasurement(double value);
    void storelastMeasurements(double addvalue);
    void setthesetpoint(double temp);
    AbstractMeasurement *last5Measurement();
    AbstractMeasurement *setpoint();
    std::string currentState();
    void warmer(double amount);
    void cooler(double amount);
    double randomDouble();
    ~Thermostat();

private:
    QString Name;
    QString IP_Address;
    QString Port;
    int Value;
    double StartTemperature;
    std::string UoM;
    AbstractMeasurement *am;
    MeasurementTemplate<double> *mt;
    MeasurementTemplate<std::vector<double>> *mt1;
    double plusminus;
    double currentvalue;
    std::vector<double> last5values;
    double lastvalue;
    double Temp;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //random nuber generator
       std::uniform_real_distribution<double> _realDistribution{0.0, 0.5};


       // ProxyInterface interface
public:
       Device *realDevice();
};

#endif // THERMOSTAT_H
