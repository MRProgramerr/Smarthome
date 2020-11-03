#include "device.h"


Device::Device(QObject *parent) : QObject(parent)
{

}

QString Device::getDeviceName(){
    return _deviceName;

}

void Device::setDeviceName(QString deviceName){
    _deviceName = deviceName;
}
