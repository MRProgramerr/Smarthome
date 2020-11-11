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

std::vector<std::vector<std::string>> Controller::registeredDevices()
{
    //  A vector of vectors to store information about each device in the
    // controller's list of devcices.
    std::vector<std::vector<std::string>> output;

    if(_listDevices.size() != 0){
        for(auto elem: _listDevices){


           std::string name = elem->realDevice()->getDeviceName().toUtf8().constData();

           std::string URL = elem->realDevice()->getIPAddressController().toUtf8().constData();

           std::string Port = elem->realDevice()->getPortNumberController().toUtf8().constData();


           std::vector<std::string> deviceInfo;
           deviceInfo.push_back(name);
           deviceInfo.push_back(URL);
           deviceInfo.push_back(Port);

           output.push_back(deviceInfo);

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
