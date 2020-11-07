#include "mainmenu.h"
#include "lightswitch.h"
#include <thread>
#include <chrono>

// If you want, change all of the QTextStream stuff to std:istream and std::ostream
// to stay with what you are familiar. Just keep in mind that it will not understand
// the various Qt objects that you might try to output.
#include <QTextStream>
#include <QUrl>
#include <QCoreApplication>

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

  // Validation
  do{

      _input >> _userInput ;

      if(_userInput < 1 || _userInput > 4){
          _display << "Please enter a valid number" << endl;
      }

  }while(_userInput < 1 || _userInput > 4);

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

  detailedUserInput(_chosenDevice);

  // Need to exit the event loop to end the application
  QCoreApplication::instance()->quit();
}


void MainMenu::detailedUserInput(QString chosenDevice)
{
    _display << "What would you like to call this " << chosenDevice << " ?" << endl;

    do{
        _input >> _inputDeviceName;

    }while(_inputDeviceName == "");

    _display << "What is the Url for the controller?" << endl;

    do{
        _input >> _inputDeviceUrl;

    }while (_inputDeviceUrl == "");

    initialisingDevice(chosenDevice,_inputDeviceName);

}

void MainMenu::initialisingDevice(QString chosenDevice, QString deviceName)
{

    if(chosenDevice == "Smart Home Controller"){
        // Logic here

    } else if(chosenDevice == "Light Switch"){

        // Logic here

    } else if(chosenDevice == "Thermostat"){

        // Logic here

    } else if(chosenDevice == "Sprinkler System"){

        // Logic here

    } else{
        _display << "Fatal error!" << endl;

    }


}










