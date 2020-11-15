#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"
#include "abstractmeasurement.h"
#include "measurementtemplate.h"
#include <QObject>
#include <random>
#include <thermostatproxyinterface.h>
#include <chrono>
#include <thread>

/**
 * @brief The Thermostat class
 * The concrete implementation of the
 * thermostat device
 */

class Thermostat : public Device, public ThermostatProxyInterface
{
    Q_OBJECT
public:

    /**
     * @brief Thermostat
     * @param name of the thermostat
     */
    Thermostat(QString name);

    /**
     * @brief getUpdateFrequency
     * @return The update frequency of the thermostat
     */
    int getUpdateFrequency() ;

    /**
     * @brief setUpdateFrequency
     * @param value
     * The setter function for the thermostat's update frequency
     */
    void setUpdateFrequency(int value);

    /**
     * @brief unitofMeasure
     * @return The unit of measure of the thermostat
     */
    std::string unitofMeasure() ;

    /**
     * @brief setUnitofMeasure
     * @param unitofMeasure
     * The setter function for the thermostat's unitofMeasure
     */
    void setUnitofMeasure(std::string unitofMeasure);

    /**
     * @brief setStartingTemperature
     * Used to set the starting temp of the thermostat
     * @param starttemp
     */
    void setStartingTemperature(double starttemp);

    /**
     * @brief getStartingTemperature
     * used to retreieve the starting temp of the thermostat.
     * @return
     */
    double getStartingTemperature();

    /**
     * @brief lastMeasurement
     * returns the most recent temperature Measurement from the Thermostat
     * @return
     */
    MeasurementTemplate<double> *lastMeasurement();

    /**
     * @brief setlastMeasurement
     * Sets the most recent temperature Measurement of the Thermostat
     * @param value
     */
    void setlastMeasurement(double value);

    /**
     * @brief storelastMeasurements
     * Used to store thermostat measurements (recent)
     * @param addvalue
     */
    void storelastMeasurements(double addvalue);

    /**
     * @brief setthesetpoint
     * Used to set the setpoint of the thermostat
     * @param temp
     */
    void setthesetpoint(double temp);

    /**
     * @brief last5Measurement
     * @return the 5 most recent temperature Measurements from the Thermostat
     */
    MeasurementTemplate<std::vector<double>> *last5Measurement();

    /**
     * @brief setpoint
     * @return a Measurement representing the currently set desired temperature
     */
    MeasurementTemplate<double> *setpoint();

    /**
     * @brief setcurrentstate
     * Used to set the current state of the thermostat
     * @param state
     */
    void setcurrentstate(std::string state);

    /**
     * @brief currentState
     * @return The state of the thermostat
     */
    MeasurementTemplate<double> *currentState();

    /**
     * @brief warmer
     * increases the setpoint to a higher temperature
     * @param amount
     */
    void warmer(double amount);

    /**
     * @brief cooler
     * decreases the setpoint to a lower temperature
     * @param amount
     */
    void cooler(double amount);

    /**
     * @brief update
     * Updates the information of the thermostat
     */
    void update();

    /**
     * @brief randomDouble
     * @return a random double
     */
    double randomDouble();

    /**
     * @brief deviceType
     * @return "Thermostat"
     */
    std::string deviceType();

    /**
     * @brief realDevice
     * @return The device itself
     */
    Device *realDevice();

private:
    QString Name;
    QString IP_Address;
    QString Port;
    int Value = 3;
    std::string cstate ="";
    double StartTemperature;
    std::string UoM ="";
    double thesetpoint;
    MeasurementTemplate<double> *mt;
    MeasurementTemplate<QString> *mt1;
    double plusminus = 0.00;
    double currentvalue = 0.00;
    QList<double> last5values;
    double lastvalue = 0.00;
    double Temp = 0.00;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //random nuber generator
    std::uniform_real_distribution<double> _realDistribution{0.0, 0.5};



};

#endif // THERMOSTAT_H
