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




class Controller : public Device
{
    Q_OBJECT
public:
    Controller(QString name);
    void registerDevice(QString deviceName, QString deviceType, QString URL);
    std::string registeredDevices();
    void unregisterDevice(QString name);
    QString currentState(QString name,QString type);


    void addFilter();
    void clearFilter();

     std::string deviceType();


    // REST API
    // report(Measurement[1..*]
    // Not implemented -> non-networking project

private:

    std::vector<ProxyInterface*> _listDevices;


signals:
    void send(QString data);



};

#endif // CONTROLLER_H
