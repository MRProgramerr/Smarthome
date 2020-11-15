#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H
#include "device.h"
#include <QList>

class DeviceController : public Device
{
    Q_OBJECT
public:
    DeviceController(QString name);
    void registerDevice(QString name,QString type, QString url);
    void registeredDevices();

private:

    QList<Device*> devicesList;


    // Device interface
public:
    std::string deviceType() override;
};

#endif // DEVICECONTROLLER_H
