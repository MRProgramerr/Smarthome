#ifndef THERMOSTATPROXY_H
#define THERMOSTATPROXY_H
#include <QString>

#include "thermostatproxyinterface.h"
#include "thermostatdevicefactory.h"
#include "devicefactory.h"
#include "thermostat.h"
#include <QObject>

/**
 * @brief The ThermostatProxy class
 * A proxy for the Thermostat device
 */

class ThermostatProxy : public QObject,public ThermostatProxyInterface
{
    Q_OBJECT
public:
    explicit ThermostatProxy(QObject *parent = nullptr);

    /**
     * @brief ThermostatProxy
     * @param name of the thermostat
     */
    ThermostatProxy(QString name );

    /**
     * @copydoc Thermostat::getUpdateFrequency()
     */
    int getUpdateFrequency() override;

    /**
     * @copydoc Thermostat::setUpdateFrequency()
     */
    void setUpdateFrequency(int value)override;

    /**
     * @copydoc Thermostat::unitofMeasure()
     */
    std::string unitofMeasure() override;

    /**
     * @copydoc Thermostat::setUnitofMeasure()
     */
    void setUnitofMeasure(std::string unitofMeasure)override;

    /**
     * @copydoc Thermostat::setStartingTemperature()
     */
    void setStartingTemperature(double starttemp)override;

    /**
     * @copydoc Thermostat::getStartingTemperature()
     */
    double getStartingTemperature()override;

    /**
     * @copydoc Thermostat::lastMeasurement()
     */
    MeasurementTemplate<double> *lastMeasurement()override;

    /**
     * @copydoc Thermostat::setlastMeasurement()
     */
    void setlastMeasurement(double value)override;

    /**
     * @copydoc Thermostat::storelastMeasurements()
     */
    void storelastMeasurements(double addvalue)override;

    /**
     * @copydoc Thermostat::setthesetpoint()
     */
    void setthesetpoint(double temp)override;

    /**
     * @copydoc Thermostat::last5Measurement()
     */
    MeasurementTemplate<QString> *last5Measurement()override;

    /**
     * @copydoc Thermostat::setpoint()
     */
    MeasurementTemplate<double> *setpoint()override;

    /**
     * @copydoc Thermostat::setcurrentstate()
     */
    void setcurrentstate(std::string state) override;

    /**
     * @copydoc Thermostat::currentState()
     */
    MeasurementTemplate<double> *currentState()override;

    /**
     * @copydoc Thermostat::warmer()
     */
    void warmer(double amount)override;

    /**
     * @copydoc Thermostat::cooler()
     */
    void cooler(double amount)override;

    /**
     * @copydoc Thermostat::randomDouble()
     */
    double randomDouble()override;

    /**
     * @copydoc Thermostat::update()
     */
    void update() override;

    /**
     * @copydoc Thermostat::setPortController()
     */
    void setPortController(QString port);

    /**
     * @copydoc Thermostat::setIPAddressController()
     */
    void setIPAddressController(QString IPAddress) ;


private:

    DeviceFactory* _deviceFactory = nullptr;

    Thermostat* _thermoStat = nullptr;


    // ProxyInterface interface
public:
    Device *realDevice() override;

    // ThermostatProxyInterface interface


signals:

    void send(QString data);

};

#endif // THERMOSTATPROXY_H
