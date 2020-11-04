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

QString Device::getIPAddressController(){
    return _IPAddressController;
}

void Device::setIPAddressController(QString IPAddress){
    _IPAddressController = IPAddress;
}

QString Device::getPortNumberController(){
    return _PortNumberController;
}

void Device::setPortNumberController(QString portNumber){
    _PortNumberController = portNumber;
}


