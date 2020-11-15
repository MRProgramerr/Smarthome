#include "devicecontroller.h"
#include "lightswitch.h"

DeviceController::DeviceController(QString name) : Device(name)
{

}

void DeviceController::registerDevice(QString name, QString type, QString url)
{
    if(type.toLower()=="lightswitch"){

        Device* d = new LightSwitch(name);
        devicesList.push_back(d);

    }



}

void DeviceController::registeredDevices(){

    for(auto elem: devicesList){
        std::cout << elem->getDeviceName().toStdString();
    }


}



std::string DeviceController::deviceType()
{
    return "controller";
}
