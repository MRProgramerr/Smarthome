#include "controller.h"

Controller::Controller(QString name)  : Device(name)
{
}

void Controller::registerDevice(QString deviceName, QString deviceType, QString URL)
{
    if(deviceType.toLower() == "lightswitch"){
        LightSwitchProxy lsp(deviceName);
        _listDevices.push_back(&lsp);
    } else if(deviceType.toLower() == "thermostat"){
        ThermostatProxy tp(deviceName);
        _listDevices.push_back(&tp);
    } else if(deviceType.toLower()== "sprinkler system"){
        SprinklerSystemProxy sp(deviceName);
        _listDevices.push_back(&sp);
    } else{
        std::cout << "No such device to register" << std::endl;
    }
}

std::vector<std::string> Controller::registeredDevices()
{

    std::vector<std::string> output;


    if(_listDevices.size() != 0){
        for(auto elem: _listDevices){


           std::string name = elem->realDevice()->getDeviceName().toUtf8().constData();

           std::string URL = elem->realDevice()->getIPAddressController().toUtf8().constData();

           std::string Port = elem->realDevice()->getPortNumberController().toUtf8().constData();


        }
    }
    else{
        std::cout << "No Registered Device...!" << std::endl;
    }

    return output;
}




std::string Controller::deviceType()
{
    return "Controller";
}
