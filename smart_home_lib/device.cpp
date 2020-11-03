#include "device.h"


Device::Device(QObject *parent) : QObject(parent)
{

}

Device::Device(QString deviceName) : _deviceName(deviceName){}

QString Device::getDeviceName(){
    return _deviceName;

}

void Device::setDeviceName(QString deviceName){
    _deviceName = deviceName;
}
