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

        // Logic here

    } else if(chosenDevice == "Sprinkler System"){

        // Logic here

    } else{
        _display << "Fatal error!" << endl;

    }

}

void MainMenu::mainMenuLightSwitch(LightSwitchProxy* lProxy)
{


        int _userInputLS = 0;

        while(_userInputLS !=6){


            _display << "--------------- Light Switch Main Menu ---------------" << endl;


            _display << "Press 1 to Turn on" << endl;
            _display << "Press 2 to Turn off" << endl;
            _display << "Press 3 to Brigthen" << endl;
            _display << "Press 4 to Dim" << endl;
            _display << "Press 5 to view status" << endl;
            _display << "Press 6 to exit" << endl;



            _input >> _userInputLS;

            for (;;) {

                if (_userInputLS >=1 && _userInputLS <=6) {
                    break;
                } else {
                    _display << "Please enter a valid option (1-6)" << endl;
                    _input >> _userInputLS;

                }
            }

            if(_userInputLS ==6) break;

            if(_userInputLS == 1){

                if(lProxy->getIsOn()){
                    _display << "The Light Switch is already turned on? Do you mean turn off?" << endl;

                }else{

                    lProxy->turnOn();
                    _display <<"The light switch has turned on" << endl;
                }

            } else if(_userInputLS ==2){

                if(!(lProxy->getIsOn())){
                    _display << "The Light Switch is already turned Off? Do you mean turn on?" << endl;

                }else{

                    lProxy->turnOff();
                    _display <<"The light switch has turned off" << endl;
                }
            }
            else{
                _display<<"Invalid Input" <<endl;
            }



        }



}











