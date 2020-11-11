#ifndef MAINMENU_H
#define MAINMENU_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <lightswitchproxy.h>
#include "proxyfactory.h"

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
   */
  void initialisingDevice(QString chosenDevice, QString deviceName);

  /**
   * @brief mainMenuLightSwitch
   * The main menu for the lightSwitch concrete
   * device. Uses proxies to talk to the
   * real device for input and output
   * @param lsp
   */
  void mainMenuLightSwitch(QString lsp);



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
  int _userInput;
  QString _inputDeviceName;
  QString _inputDeviceUrl;
  QString _chosenDevice;
  ProxyFactory* _proxyFactory;


};

#endif // MAINMENU_H
