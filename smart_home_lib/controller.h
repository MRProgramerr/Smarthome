#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "device.h"
#include <QString>
#include <vector>
#include <iostream>

#include "lightswitchproxy.h"
#include "proxyinterface.h"
#include "thermostatproxy.h"
#include "sprinklersystemproxy.h"
#include "measurementfilters.h"

/**
 * @brief The Controller class
 * This is the smart home controller
 * which can send and/or recieve information
 * from all the smart home devices.
 */


class Controller : public Device
{
    Q_OBJECT
public:

    /**
     * @brief Controller
     * @param name
     */
    Controller(QString name);

    /**
     * @brief registerDevice : Adds an device (proxy)
     * to a list which is then used for various
     * purposes
     * @param deviceName name of the device
     * @param deviceType type of the device
     * @param URL of the device
     */
    void registerDevice(QString deviceName, QString deviceType, QString URL);

    /**
     * @brief registeredDevices
     * @return A string representation of all the devices in the
     * list of the controller.
     */
    std::string registeredDevices();

    /**
     * @brief unregisterDevice
     * this is used to remove a device from the
     * devices list
     * @param name of the device to be removed
     */
    void unregisterDevice(QString name);

    /**
     * @brief currentState
     * returns current state of all the devices in the
     * device list.
     * @param name
     * @param type
     * @return
     */
    QString currentState(QString name,QString type);

    /**
     * @brief addFilter
     * Adds a measruement filter to the information
     * received from the smart home device
     */
    template<class T>
    void addFilter(QString name, MeasurementTemplate<T> type, std::string filtertype, T val);
    /**
     * @brief clearFilter
     * Removes a measurement filter
     */
    void clearFilter();

    /**
     * @brief deviceType
     * Overriden method to return
     * "controller"
     * @return
     */
    std::string deviceType();

    /**
     * @brief getListDevices
     * @return A list of all the devices proxies stored
     */
    std::vector<ProxyInterface*> getListDevices();


    // REST API
    // report(Measurement[1..*]
    // Not implemented -> non-networking project

private:

    std::vector<ProxyInterface*> _listDevices;


signals:

    /**
     * @brief send
     * Used to send important information
     * to be received by the mainmenu
     * @param data
     */
    void send(QString data);


};

#endif // CONTROLLER_H
