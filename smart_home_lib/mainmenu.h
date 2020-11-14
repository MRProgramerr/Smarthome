#ifndef MAINMENU_H
#define MAINMENU_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <lightswitchproxy.h>
#include "proxyfactory.h"
#include "sprinklersystemproxy.h"
#include "thermostatproxy.h"

class MainMenu : public QObject
{
  Q_OBJECT
public:
  explicit MainMenu(QTextStream &display, QTextStream &input, QObject *parent = nullptr);
  virtual ~MainMenu() = default;

  /**
   * @brief displayWelcome display an intial welcome message including the
   * student's name and game title.
   * @param author the name of the student
   * @param title the name of the assignment
   */
  void displayWelcome(const QString &title, const QString &group, const QStringList &members) const;

  /**
   * @brief detailedUserInput
   * The function to ask the user for specific details about
   * a chosen device
   * @param chosenDevice the device chosen by the user
   *
   */
  void detailedUserInput(QString chosenDevice);

  /**
   * @brief initialisingDevice
   * The function to create a proxy using the
   * abstract factory pattern
   * @param chosenDevice
   * @param deviceName
   * @param inputDeviceUrl
   * @param inputProxy
   */
  void initialisingDevice(QString chosenDevice, QString deviceName,QString inputDeviceUrl,QString inputProxy);

  /**
   * @brief mainMenuLightSwitch
   * The main menu for the lightSwitch concrete
   * device. Uses proxies to talk to the
   * real device for input and output
   * @param lsp
   */
  void mainMenuLightSwitch(LightSwitchProxy* proxy);


  /**
   * @brief mainMenuSprinklerSystem
   * The main menu for the sprinkler system concrete
   * device. Uses proxies to talk to the real device
   * for input device and output device.
   * @param proxy
   */
  void mainMenuSprinklerSystem(SprinklerSystemProxy* sProxy);

  /**
   * @brief mainMenuThermostat
   * The main menu for the sprinkler system concrete
   * device. Uses proxies to talk to the real device
   * for input device and output device.
   * @param proxy
   */
  void mainMenuThermostat(ThermostatProxy* tProxy);

public slots:
  /**
   * @brief run Begin executing the main menu.
   *
   * This is a slot so that it can be called on thread start. Refer to the main function to see how this works.
   */
  void run();

private:

  QTextStream &_display;
  QTextStream &_input;
  int _userInput = 0;
  QString _inputDeviceName;
  QString _inputDeviceUrl;
  QString _chosenDevice;
  ProxyFactory* _proxyFactory = nullptr;
  QString _inputPort;
  int thermoupdatefrequency = 3;
   std::string confirm ="";
   double starttemp =0;
   std::string uom ="";
   double settemp = 0;
   bool getupdate = true;

};

#endif // MAINMENU_H
