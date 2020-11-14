#include "mainmenu.h"
#include "lightswitch.h"
#include <thread>
#include <chrono>
#include <QUrl>
#include <QCoreApplication>
#include "lightswitchproxy.h"
#include <iostream>
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
        // Logic here

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

    _display <<"Enter water consumption per interval(litres) " <<endl;
    _input >> _waterCons;
    for (;;) {

        if (_waterCons >=1 && _waterCons <=5) {
            break;
        } else {
            _display << "You dont wanna ruin your plants. Enter between 1 and 5 Litres" << endl;
            _input >> _waterCons;

        }
    }

    sProxy->setWaterConsumptionPerInterval(_waterCons);

    while(_userInputSS !=7){



        _display << endl;
        _display << "--------------- Sprinkler System Main Menu ---------------" << endl;

        _display << endl;
        _display << "Press 1 to Turn on" << endl;
        _display << "Press 2 to Turn off" << endl;
        _display << "Press 3 to change water consumption per interval" << endl;
        _display << "Press 4 to schedule a timer" << endl;
        _display << "Press 5 to view live water consumption updates" << endl;
        _display << "Press 6 to view the current state of sprinkler" << endl;
        _display << "Press 7 to exit " << endl;

        _input >> _userInputSS;

        if(_userInputSS ==1){

            sProxy->turnOn();
            on = QDateTime::currentDateTime();


        }else if(_userInputSS ==2){

            if(sProxy->getIsOn()){
                sProxy->turnOff();
                off = QDateTime::currentDateTime();
                _display << endl;
                _display << "Sprinkler System was on for: "<<sProxy->waterConsumptionPerCycle(on,off)/(sProxy->getWaterConsumptionPerInterval()/5)/1000 <<" seconds. " <<endl;
                _display << "Sprinkler System used: "<<sProxy->waterConsumptionPerCycle(on,off)/1000 <<" litre(s) water. " <<endl;
                totalOn += sProxy->waterConsumptionPerCycle(on,off)/(sProxy->getWaterConsumptionPerInterval()/9)/1000;

            }

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


            if(sProxy->getIsOn()){

                _display << endl;
                _display <<"Press Enter to move to next update" << endl << "Press ESC to exit " << endl;


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
    }
}

void MainMenu::mainMenuThermostat(ThermostatProxy *tProxy)
{

    // Connects Light Switch proxy signals with the main menu
    // slot to recieve state change informations.
    connect(tProxy,SIGNAL(send(QString)),this,SLOT(listen(QString)));

    int _userInputTH =0;

    _display <<"Do you want to change the -Update Frequency- default value: 3 seconds [Y/N]" <<endl;
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
            _display<<"INVALID SELECTION!! select [Y/N] only"<<endl;
    }

    _display <<"Please enter The setpoint"<<endl;
    _input>>settemp;
    tProxy->setthesetpoint(settemp);

    _display <<"Please enter The Unit Of Measurement F: Farenheit, C: Celcius"<<endl;
    for (;;) {
        std::cin>>uom;

        if (uom == "C" || uom == "F" || uom == "f" || uom == "c") {
            break;
        }

        else {
            _display << "Invalid selection please select between [F/C] only" << endl;
            std::cin>>uom;

        }
    }

    tProxy->setUnitofMeasure(uom);

    _display <<endl;
    _display<<"Please enter The Start Temperature"<<endl;
    _input>>starttemp;
    tProxy->setStartingTemperature(starttemp);

    while(_userInputTH != 9){

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

            std::cout<<tProxy->lastMeasurement()->deviceName()+ " || " + tProxy->lastMeasurement()->measurementType() + "|| " + tProxy->lastMeasurement()->unitofMeasure() + " || ";
            _display<<tProxy->lastMeasurement()->value().toString()<<endl;

        }

        if(_userInputTH == 2 ){
            std::cout<<tProxy->lastMeasurement()->deviceName()+ " || " + tProxy->lastMeasurement()->measurementType() + "|| " + tProxy->lastMeasurement()->unitofMeasure() + " || ";
            std::vector<MeasurementTemplate<double>> *m5 = new std::vector<MeasurementTemplate<double>>;
            std::vector<MeasurementTemplate<double>>::iterator it;

            for(it = m5->begin(); it!= m5->end(); it++)
                std::cout<<it->value().String;
        }
        if(_userInputTH == 3 ){
            std::cout<<tProxy->setpoint()->deviceName()+ " || " + tProxy->setpoint()->measurementType() + "|| " + tProxy->setpoint()->unitofMeasure() + " || ";
            _display<<tProxy->setpoint()->value().toString()<<endl;
        }

        if(_userInputTH == 4 ){
            if(getupdate == true){
                std::cout<<tProxy->currentState()->deviceName()+ " || " + tProxy->currentState()->measurementType() + "|| " + tProxy->currentState()->unitofMeasure() + " || ";
                _display<<tProxy->currentState()->value().toString()<<endl;

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







