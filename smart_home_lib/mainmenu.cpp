#include "mainmenu.h"
#include "lightswitch.h"
#include <thread>
#include <chrono>
#include <QUrl>
#include <QCoreApplication>
#include "lightswitchproxy.h"
#include <iostream>
#include <sstream>
#include "lightswitchproxyfactory.h"
#include "proxyfactory.h"
#include "measurementtemplate.h"
#include "abstractmeasurement.h"
#include "sprinklersystemproxyfactory.h"
#include "sprinklersystem.h"
#include <QTimer>
#include <conio.h>
#include "thermostatproxyfactory.h"
#include "thermostatproxy.h"
#include "thermostat.h"
#include "controllerfactory.h"


MainMenu::MainMenu(QTextStream &display, QTextStream &input, QObject *parent)
    : QObject{parent}, _display{display}, _input{input}
{
}

void MainMenu::displayWelcome(const QString &title, const QString &group, const QStringList &members) const
{
    QString welcomeText{"Welcome to " + title};
    QString groupText{"Developed by " + group + ":"};

    _display << welcomeText << endl
             << groupText << endl;

    for (auto name: members) {
        _display << "- " << name << endl;
    }

    _display << "COMP 3023 Software Development with C++" << endl << endl;

}


void MainMenu::run()
{

    _display << "Preparing to initialise Smart Home System" << endl;
    _display << "What type of device do you want to configure?" <<endl;
    _display << "1.Smart Home Controller" << endl << "2.Light Switch" << endl << "3.Thermostat" << endl << "4.Sprinkler System" <<endl;

    // User-Input Validation
    do{

        _input >> _userInput ;

        // Displays an error if input not in the valid range
        if(_userInput < 1 || _userInput > 4){
            _display << "Please enter a valid number" << endl;
        }

        // Loops until a correct input is provided.
    }while(_userInput < 1 || _userInput > 4);

    // Switch to accomodate
    // the different user inputs
    switch (_userInput) {

    case 1 : {
        _chosenDevice = "Smart Home Controller";
        break;
    }
    case 2 : {
        _chosenDevice = "Light Switch";
        break;
    }
    case 3 : {
        _chosenDevice = "Thermostat";
        break;
    }
    case 4 : {
        _chosenDevice = "Sprinkler System";
        break;
    }

    }

    // Calls the detailed user input function
    detailedUserInput(_chosenDevice);

    // Need to exit the event loop to end the application
    QCoreApplication::instance()->quit();
}

void MainMenu::listen(QString info)
{
    _display << "The Device said.." << info << endl;
}


void MainMenu::detailedUserInput(QString chosenDevice)
{
    _display << "What would you like to call this " << chosenDevice << " ?" << endl;

    // User-validation
    do{
        _input >> _inputDeviceName;

    }while(_inputDeviceName == "");

    // Prompts for the URl
    // Note -> URL is not used anywhere in this
    // application (Non-networking)
    _display << "What is the Url for the controller?" << endl;

    // Validation
    do{
        _input >> _inputDeviceUrl;

    }while (_inputDeviceUrl == "");

    _display << "What is the PORT for the controller?" << endl;

    // Validation
    do{
        _input >> _inputPort;

    }while (_inputPort == "");


    _display << "Initialising....." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    initialisingDevice(chosenDevice,_inputDeviceName,_inputDeviceUrl,_inputPort);

}

// Call main menu for each concrete device
void MainMenu::initialisingDevice(QString chosenDevice, QString deviceName,QString inputDeviceUrl,QString inputPort)
{


    if(chosenDevice == "Smart Home Controller"){

        // Creates a controller object and
        // then sends it as a parameter to the
        // controller main menu
        Controller* c = new Controller(deviceName);
        c->setIPAddressController(inputDeviceUrl);
        c->setPortNumberController(inputPort);
        mainMenuController(c);


    } else if(chosenDevice == "Light Switch"){

        // Creates a lightSwitchProxy Factory
        // and then uses it to create a concrete
        // Light Switch proxy object
        LightSwitchProxyFactory lf(deviceName);
        LightSwitchProxy* lProxy =  dynamic_cast<LightSwitchProxy*>( _proxyFactory->createProxy(&lf));

        // Sets the paramters such as URL, Port
        lProxy->setIPAddressController(inputDeviceUrl);
        lProxy->setPortController(inputPort);

        // Calls out the main menu for the
        // light switch
        mainMenuLightSwitch(lProxy);

    } else if(chosenDevice == "Thermostat"){

        // Creates a thermostat Factory
        // and then uses it to create a concrete
        // thermostat proxy object

        ThermostatProxyFactory th(deviceName);
        ThermostatProxy *tProxy = dynamic_cast<ThermostatProxy*>( _proxyFactory->createProxy(&th));

        // Sets the paramters such as URL, Port
        tProxy->setIPAddressController(inputDeviceUrl);
        tProxy->setPortController(inputPort);

        // Calls out the main menu for the
        // light switch
        mainMenuThermostat(tProxy);


    } else if(chosenDevice == "Sprinkler System"){

        //Creates a sprinkler system proxy factory
        // and then uses it to create a concrete
        // Sprinkler proxy object
        SprinklerSystemProxyFactory sdf(deviceName);
        SprinklerSystemProxy* sProxy =  dynamic_cast<SprinklerSystemProxy*>( _proxyFactory->createProxy(&sdf));

        sProxy->setIPAddressController(inputDeviceUrl);
        sProxy->setPortController(inputPort);


        // Calls out the main menu for the
        // sprinkler system
        mainMenuSprinklerSystem(sProxy);


    } else{
        _display << "Fatal error!" << endl;

    }

}

void MainMenu::mainMenuController(Controller* controller)
{
    // connects Controller signas with main menu to recieve updates on registered devices
    connect(controller,SIGNAL(send(QString)),this,SLOT(listen(QString)));

    int _userInputC = 0;

    while(_userInputC != 6)
    {
        // Loops this menu
        _display << endl;
        _display << "--------------- Smart Home Controller Main Menu ---------------" << endl;
        _display << "Press 1 to Register Device" << endl;
        _display << "Press 2 to View Registered Devices" << endl;
        _display << "Press 3 to Unregister Device" << endl;
        _display << "Press 4 to view status of a device" << endl;
        _display << "Press 5 to interact with a device directly" << endl;
        _display << "Press 6 to exit" << endl;

        _input >> _userInputC;

        // If exits
        if(_userInputC == 6)break;

        // Other options
        else if(_userInputC == 1){

            // Inputs the required paramters
            // for registering a device to the
            // controller
            QString deviceName;
            QString deviceType;
            QString URL;
            _display << "Enter device name" << endl;
            _input >> deviceName;
            _display << "Enter device type(lightswitch,sprinkler,thermostat)" << endl;
            _input >> deviceType;
            _display << "Enter device URL" << endl;
            _input >> URL;

            // Registers the device
            controller->registerDevice(deviceName, deviceType, URL);
        }

        else if(_userInputC == 2){

            // Displays all the registered devices in the controller
            _display << QString::fromStdString(controller->registeredDevices());
        }
        else if(_userInputC == 3){
            QString deviceName;
            QString deviceType;
            _display << "Enter device name" << endl;
            _input >> deviceName;
            controller->unregisterDevice(deviceName);
        }

        else if(_userInputC ==4){
            controller->currentState("","");
        }

        // This allows the user to interact with any registered device directly
        // by passing the created device proxy into their relavant device menu.
        else if(_userInputC ==5){

            if(controller->getListDevices().size() != 0){
                int input = 0;
                _display<<"--------------------------------------------------------"<<endl;
                _display << "The Devices you can interact with are:" << endl;
                _display << QString::fromStdString(controller->registeredDevices());
                _display<<"--------------------------------------------------------"<<endl;
                _display << "Choose from " << "1 and " <<  controller->getListDevices().size()<<endl;
                _input >> input;

                // Input validation loop
                for (;;) {

                    if (input >=1 && input <= (int)controller->getListDevices().size()) {
                        break;
                    } else {
                        _display << "Invalid input.. try again" << endl;
                        _input >> input;

                    }
                }

                QString deviceType = QString::fromStdString(controller->getListDevices().at(input-1)->realDevice()->deviceType());

                // Dynamic casting of the abstract devices to
                // appropriate concrete devices and then
                // calling out main menus
                if(deviceType.toLower()=="light switch"){

                    LightSwitchProxy* ls = dynamic_cast<LightSwitchProxy*>(controller->getListDevices().at(input-1));
                    mainMenuLightSwitch(ls);

                } else if(deviceType.toLower()=="sprinkler system"){

                    SprinklerSystemProxy* ss = dynamic_cast<SprinklerSystemProxy*>(controller->getListDevices().at(input-1));
                    mainMenuSprinklerSystem(ss);

                } else if(deviceType.toLower()=="thermostat"){

                    ThermostatProxy* tp = dynamic_cast<ThermostatProxy*>(controller->getListDevices().at(input-1));
                    mainMenuThermostat(tp);

                }

            } else{
                _display <<"No Registered devices..." << endl;
            }


        }

        else{
            _display << "Please enter a valid option (1-6)" << endl;
            _input >> _userInputC;
        }

    }
}

void MainMenu::mainMenuLightSwitch(LightSwitchProxy* lProxy)
{

    // Connects Light Switch proxy signals with the main menu
    // slot to recieve state change informations.
    connect(lProxy,SIGNAL(send(QString)),this,SLOT(listen(QString)));

    // For user input
    int _userInputLS = 0;

    // Until user doesnt exit
    while(_userInputLS !=6){

        // Loops this menu
        _display << endl;
        _display << "--------------- Light Switch Main Menu ---------------" << endl;
        _display << "Press 1 to Turn on" << endl;
        _display << "Press 2 to Turn off" << endl;
        _display << "Press 3 to Brigthen" << endl;
        _display << "Press 4 to Dim" << endl;
        _display << "Press 5 to view status" << endl;
        _display << "Press 6 to exit" << endl;


        _input >> _userInputLS;

        // Validation loop
        for (;;) {

            if (_userInputLS >=1 && _userInputLS <=6) {
                break;
            } else {
                _display << "Please enter a valid option (1-6)" << endl;
                _input >> _userInputLS;

            }
        }

        // If user exits
        if(_userInputLS ==6) break;

        // Other options
        // Calls out appt functions on the
        // lightswitch proxy which
        // send out a signal
        if(_userInputLS == 1){

            lProxy->turnOn();

        } else if(_userInputLS ==2){

            lProxy->turnOff();

        } else if(_userInputLS ==3){

            lProxy->brighten();

        } else if(_userInputLS ==4){

            lProxy->dim();

        } else if(_userInputLS == 5){

            lProxy->currentStatus();

        }
    }

}

void MainMenu::mainMenuSprinklerSystem(SprinklerSystemProxy *sProxy)
{

    // Connects Light Switch proxy signals with the main menu
    // slot to recieve state change informations.
    connect(sProxy,SIGNAL(send(QString)),this,SLOT(listen(QString)));

    QDateTime on;
    QDateTime off;
    QDateTime current;
    double totalOn = 0;


    int _userInputSS =0;
    double _waterCons = 0;

    _display << endl;
    _display <<"Enter water consumption per interval(litres) " <<endl;
    _input >> _waterCons;

    // Validation loop
    for (;;) {

        if (_waterCons >=1 && _waterCons <=5) {
            break;
        } else {
            _display << "You dont wanna ruin your plants. Enter between 1 and 5 Litres" << endl;
            _input >> _waterCons;

        }
    }

    sProxy->setWaterConsumptionPerInterval(_waterCons);

    while(_userInputSS !=8){



        _display << endl;
        _display << "--------------- Sprinkler System Main Menu ---------------" << endl;

        _display << endl;
        _display << "Press 1 to Turn on" << endl;
        _display << "Press 2 to Turn off" << endl;
        _display << "Press 3 to change water consumption per interval" << endl;
        _display << "Press 4 to schedule a timer" << endl;
        _display << "Press 5 to view live water consumption updates" << endl;
        _display << "Press 6 to view the current state of sprinkler" << endl;
        _display<<  "Press 7 to view Water Usage"<<endl;
        _display << "Press 8 to exit " << endl;

        _input >> _userInputSS;

        if(_userInputSS ==1){

            sProxy->turnOn();
            on = QDateTime::currentDateTime();


       // Turn off function records the time the sprinkler was turned on and
       // uses it to calculate the water consumption for that interval
        }else if(_userInputSS ==2){

            if(sProxy->getIsOn()){
                sProxy->turnOff();
                off = QDateTime::currentDateTime();
                _display << endl;
                _display << "Sprinkler System was on for: "<<sProxy->waterConsumptionPerCycle(on,off)/(sProxy->getWaterConsumptionPerInterval()/5)/1000 <<" seconds. " <<endl;
                _display << "Sprinkler System used: "<<sProxy->waterConsumptionPerCycle(on,off)/1000 <<" litre(s) water. " <<endl;
                totalOn += sProxy->waterConsumptionPerCycle(on,off)/(sProxy->getWaterConsumptionPerInterval()/9)/1000;

            }

        // Changing water consumption menu
        }else if(_userInputSS ==3){

            _display << endl;
            _display <<"Enter water consumption per interval(litres) " <<endl;
            _input >> _waterCons;
            for (;;) {

                if (_waterCons >=1 && _waterCons <=5) {
                    break;
                } else {
                    _display << endl;
                    _display << "You dont wanna ruin your plants. Enter between 1 and 5 Litres" << endl;
                    _input >> _waterCons;

                }
            }

            sProxy->setWaterConsumptionPerInterval(_waterCons);

        }else if(_userInputSS ==4){

            double delaySeconds =0;
            double durationSeconds =0;

            _display << endl;
            _display << "What is the delay after which you wanna turn the System?" << endl;
            _input >> delaySeconds;

            _display << endl;
            _display << "What is the duration for which you wanna turn the System?" << endl;
            _input >> durationSeconds;

            _display << endl;

            sProxy->schedule(QTime(0,0,delaySeconds),QTime(0,0,durationSeconds));
            _display << endl;
            _display << "Sprinkler System was on for: "<< durationSeconds <<" seconds. " <<endl;
            _display << "Sprinkler System used: "<<durationSeconds*sProxy->getWaterConsumptionPerInterval()/9 <<" litre(s) water. " <<endl;

        }else if(_userInputSS ==5){


            // shows the live updates of the sprinkler each time the user hits enter.
            // the user can press esc to get out of this menu

            if(sProxy->getIsOn()){

                _display << endl;
                _display <<"Press Enter to move to next update" << endl << "Press ESC to exit " << endl;

                // Continues loop until enter/esc.
                char ch;
                bool loop=false;

                while(loop==false)
                {

                    current =  QDateTime::currentDateTime();

                    _display << "Water used as of " << current.time().toString() <<" " << sProxy->waterConsumptionPerCycle(on,current)/1000 << " litres" <<endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    ch=getch();

                    if(ch==27)
                        loop=true;
                }


            }else{
                _display << endl;
                _display << "Turn on the system to get updates" << endl;
            }


        }else if(_userInputSS ==6){

            for(auto elem : sProxy->currentState()){

                _display << elem->value().toString();
            }


        }
         if(_userInputSS ==7){

             for(int i = 0 ;i <sProxy->waterUsage().size();i++){
                 _display<< "Current Water Usage:"<<sProxy->waterUsage()[i]->value().toString();
                 _display<<"Total Water Usage:"<<sProxy->waterUsage()[i+1]->value().toString();
//                 qDeleteAll(sProxy->waterUsage());
                 break;
             }
         }
    }
}

void MainMenu::mainMenuThermostat(ThermostatProxy *tProxy)
{

    // Connects Light Switch proxy signals with the main menu
    // slot to recieve state change informations.
    connect(tProxy,SIGNAL(send(QString)),this,SLOT(listen(QString)));

    int _userInputTH =0;

    _display <<"Do you to change the -Update Frequency- default value: 3 seconds [y/n]" <<endl;
    for(;;){
        std::cin>>confirm;

        if(confirm =="Y" || confirm =="y" ){
            _display<<"Enter the update frequency"<<endl;
            _input>>thermoupdatefrequency;
            tProxy->setUpdateFrequency(thermoupdatefrequency);
            break;
        }
        else if(confirm =="N" ||confirm == "n"){
            break;
        }
        else
            _display<<"INVALID SELECTION!! Select [y/n] only "<<endl;
    }

    _display <<"Please enter The setpoint"<<endl;
    _input>>settemp;
    tProxy->setthesetpoint(settemp);

    _display <<"Please enter Unit of measure 'F' for farenheit adm 'C' for Celcius"<<endl ;
    std::cin>>uom;

    for (;;) {

        if (uom == "C" || uom == "F" || uom == "f" || uom == "c") {
            break;
        } else {
            _display << "Invalid selection please select between [F/C] only" << endl;
            std::cin>>uom;
            tProxy->setUnitofMeasure(uom);
        }
    }
    _display<<"Please enter The Start Temperature"<<endl;
    _input>>starttemp;
    tProxy->setStartingTemperature(starttemp);

    // User input output loop
    while(_userInputTH != 9){

        tProxy->update();

        _display << endl;
        _display << "--------------- Thermostat Main Menu ---------------" << endl;
        _display << endl;
        _display << "Press 1 for last Measurement" << endl;
        _display << "Press 2 for last 5 Measurement" << endl;
        _display << "Press 3 to view the Setpoint" << endl;
        _display << "Press 4 to view the Current State " << endl;
        _display << "Press 5 to Increase the Setpoint" << endl;
        _display << "Press 6 to Decrease the Setpoint" << endl;
        _display << "Press 7 to Disable the temperature updates" << endl;
        _display << "Press 8 to Enable the temperature updates " << endl;
        _display << "Press 9 to exit" << endl;

        _input >> _userInputTH;

        for (;;) {

            if (_userInputTH >=1 && _userInputTH <=9) {
                break;
            } else {
                _display << "Please enter a valid option (1-9)" << endl;
                _input >> _userInputTH;

            }
        }

        if(_userInputTH == 9 ) break;

        if(_userInputTH == 1 ){

            _display<<"taken at"+tProxy->lastMeasurement()->timeStamp().toString()<<endl;
           _display<<" || "<<QString::fromStdString(tProxy->lastMeasurement()->deviceName())<< " || "<<endl;
           _display<<QString::fromStdString(tProxy->lastMeasurement()->measurementType())<< ": ";
            _display<<"    "+tProxy->lastMeasurement()->value().toString();
            _display<<QString::fromStdString(uom);
        }

        if(_userInputTH == 2 ){
            _display<<"taken at"+tProxy->last5Measurement()->timeStamp().toString();
            _display<<" || "<<QString::fromStdString(tProxy->last5Measurement()->deviceName())<<" || ";
             _display<<"    "<<QString::fromStdString(tProxy->last5Measurement()->measurementType())<<endl;
            _display<<tProxy->last5Measurement()->value().toString();
        }
        if(_userInputTH == 3 ){
            _display<<"taken at"+tProxy->setpoint()->timeStamp().toString();
            _display<<" || "<<QString::fromStdString(tProxy->setpoint()->deviceName())<<" || "<<endl;
            _display<<QString::fromStdString(tProxy->setpoint()->measurementType())<<": ";
            _display<<tProxy->setpoint()->value().toString();
            _display<<QString::fromStdString(uom);
        }

        if(_userInputTH == 4 ){
            if(getupdate == true){
                _display<<"taken at"+tProxy->currentState()->timeStamp().toString();
                _display<<" || "<<QString::fromStdString(tProxy->currentState()->deviceName())<<" || "<<endl;
                 _display<<QString::fromStdString(tProxy->currentState()->measurementType())<< ": "<<QString::fromStdString(tProxy->currentState()->unitofMeasure())<<" ";
                _display<<tProxy->currentState()->value().toString();
                _display<<QString::fromStdString(uom);

            }
            else {
                _display<<"Updates are turned off"<<endl;
                _display<<"**Press 8 to Enabble** "<<endl;
            }
        }

        if(_userInputTH == 5 ){
            _display<<" Please enter the amount"<<endl;
            double amt=0;
            std::cin>>amt;
            tProxy->warmer(amt);
            std::cout<<"Setpoint increased by "<<amt<<std::endl;
        }
        if(_userInputTH == 6 ){
            _display<<" Please enter the amount"<<endl;
            double amt=0;
            std::cin>>amt;
            tProxy->cooler(amt);
            std::cout<<"Setpoint decreased by "<<amt<<std::endl;
        }
        if(_userInputTH == 7 ){
            _display<<"Updates turned Off"<<endl;
            getupdate = false;
        }

        if(_userInputTH == 8 ){
            _display<<"Updates turned On"<<endl;
            getupdate = true;
        }
    }


}







