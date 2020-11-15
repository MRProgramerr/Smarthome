#include "controller.h"

Controller::Controller(QString name)  : Device(name)
{
}

void Controller::registerDevice(QString deviceName, QString deviceType, QString URL)
{
    bool uniqueName = true;
    int length = _listDevices.size();
    for(int i = 0; i < length; i++){
        if(_listDevices[i]->realDevice()->getDeviceName() == deviceName)
        {
            uniqueName = false;
        }
    }
    if(uniqueName == true)
    {
        if(deviceType.toLower() == "lightswitch"){

            ProxyInterface* lsp =  new LightSwitchProxy(deviceName);
            lsp->realDevice()->setIPAddressController(URL);
            _listDevices.push_back(lsp);
            emit send("Successfully registered " + deviceName + " as a lightswitch");

        } else if(deviceType.toLower() == "thermostat"){

            ProxyInterface* tp = new ThermostatProxy(deviceName);
            tp->realDevice()->setIPAddressController(URL);
            _listDevices.push_back(tp);
            emit send("Successfully registered " + deviceName + " as a thermostat");

        } else if(deviceType.toLower()== "sprinkler"){

            ProxyInterface* sp=new SprinklerSystemProxy (deviceName);
            sp->realDevice()->setIPAddressController(URL);
            _listDevices.push_back(sp);
            emit send("Successfully registered " + deviceName + " as a sprinkler system");

        } else{
            emit send("No such device type");
        }
    }
    else{
        std::cout << "That device name is unavailable" << std::endl;
    }
}

std::string Controller::registeredDevices()
{

    std::string output;

    if(_listDevices.size() != 0){
        for(auto elem: _listDevices){


            output += "Device Name: ";
            output+= elem->realDevice()->getDeviceName().toUtf8().constData();

            output += " Device TYPE: ";

            output+= elem->realDevice()->deviceType();
            output += " Device PORT: ";
            output+= elem->realDevice()->getIPAddressController().toUtf8().constData();

            output+= "\n";

        }
    }
    else{
        emit send( "No Registered Device...!" );
    }

    return output;
}


void Controller::unregisterDevice(QString deviceName)
{
    // new vector that is a copy of the list of devices
    std::vector<ProxyInterface*> _copyListDevices = _listDevices;


    // if the list of devices is not empty
    if(_copyListDevices.size() != 0){
        // everything is removed from the list of devices
        _listDevices.clear();
        int length = _copyListDevices.size();
        bool found = false;
        // loop through the copy list and registers every device from that list besides the one being unregistered
        for (int i = 0; i < length ; i++){
            // when the device name in the copy list of devices is not the same as the removed device name
            if(deviceName != _copyListDevices[i]->realDevice()->getDeviceName().toUtf8().constData()){

                // converts device type std::string to a qstring so it can be used to register devices
                QString type = QString::fromStdString(_copyListDevices[i]->realDevice()->deviceType());

                // that device is registered to the list of devices
                registerDevice(_copyListDevices[i]->realDevice()->getDeviceName(), type, _copyListDevices[i]->realDevice()->getIPAddressController());
            }
            else{
                // if the specified device name is found
                found = true;
                emit send("Successfully unregistered " + deviceName);
            }
        }
        // if the specified device name was not found in the lise
        if(found == false){
            emit send( "No such device to unregister" );
        }
    }

    else{
        emit send("No registered devices to unregister");
    }
}

QString Controller::currentState(QString name,QString type){
    int length = _listDevices.size();

    // if name and type are left blank
    // returns current state of every device in the list
    if(name == "" && type == ""){

        QString output;

        for (int i = 0; i < length ; i++){
            QString deviceType = QString::fromStdString(_listDevices[i]->realDevice()->deviceType());
            if(deviceType.toLower() == "lightswitch"){

            }
            else if(deviceType.toLower() == "thermostat"){
                // return summary of currentstate from thermostat proxy of that device
            }
            else if(deviceType.toLower()== "sprinkler system"){
                // return summary of currentstate from sprinkler proxy of that device
            }
        }
    }

    // if only the name is left blank
    // returns all devices of the specified type
    else if(name == ""){
        for (int i = 0; i < length ; i++){
            QString deviceType = QString::fromStdString(_listDevices[i]->realDevice()->deviceType());
            if(deviceType == type){
                if(deviceType.toLower() == "lightswitch"){
                    // return summary of currentstate from lightswitch proxy of that device
                }
                else if(deviceType.toLower() == "thermostat"){
                    // return summary of currentstate from thermostat proxy of that device

                }
                else if(deviceType.toLower()== "sprinkler system"){
                    // return summary of currentstate from sprinkler proxy of that device
                }
            }
        }
    }

    // if only type is left blank
    // returns all devices with the specified name
    else if(type == ""){
        for (int i = 0; i < length ; i++){
            QString deviceType = QString::fromStdString(_listDevices[i]->realDevice()->deviceType());
            if(_listDevices[i]->realDevice()->getDeviceName() == name){
                if(deviceType.toLower() == "lightswitch"){
                    // return summary of currentstate from lightswitch proxy of that device
                }
                else if(deviceType.toLower() == "thermostat"){
                    // return summary of currentstate from thermostat proxy of that device

                }
                else if(deviceType.toLower()== "sprinkler system"){
                    // return summary of currentstate from sprinkler proxy of that device
                }
            }
        }
    }
    // else if name and type are not blank
    // returns the device with the specific name and type
    else
    {
        for (int i = 0; i < length ; i++){
            QString deviceType = QString::fromStdString(_listDevices[i]->realDevice()->deviceType());
            if(_listDevices[i]->realDevice()->getDeviceName() == name && deviceType == type){
                if(deviceType.toLower() == "lightswitch"){
                    // return summary of currentstate from lightswitch proxy of that device
                }
                else if(deviceType.toLower() == "thermostat"){
                    // return summary of currentstate from thermostat proxy of that device
                }
                else if(deviceType.toLower()== "sprinkler system"){
                    // return summary of currentstate from sprinkler proxy of that device
                }
            }
        }
    }
}



std::string Controller::deviceType()
{
    return "Controller";
}

std::vector<ProxyInterface *> Controller::getListDevices()
{
    return _listDevices;
}
