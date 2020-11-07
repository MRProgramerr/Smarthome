 #include <QCoreApplication>
#include <QTextStream>
#include <QThread>
#include "mainmenu.h"
#include "lightswitch.h"
#include "sprinklersystem.h"
#include <limits>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QTextStream input{stdin};
  QTextStream output{stdout};
  MainMenu* menu{new MainMenu{output, input}};
  menu->displayWelcome("Smart Home System Base Project", "WE WHO SHALL NOT BE NAMED", {"Alessio, Harkaran, Husain, Shivam Verma"});

  // Configure a separate thread for the menu to run in
  QThread userThread{};
  menu->moveToThread(&userThread);
  QObject::connect(&a, &QCoreApplication::aboutToQuit, [&userThread]() { userThread.quit(); userThread.wait(); });
  QObject::connect(&userThread, &QThread::finished, menu, &QObject::deleteLater);
  QObject::connect(&userThread, &QThread::started, menu, &MainMenu::run);
  userThread.start();


  LightSwitch ls("Karan");
  ls.menuLightSwitch();

//    SprinklerSystem ss("Sprinkler1");
//    ss.schedule(1,1);


  // Run the main event loop to keep the program running
  return a.exec();
}
