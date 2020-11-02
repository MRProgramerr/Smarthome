#include "mainmenu.h"

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
//  // remove this line, or at least comment it out until you have got it set up yourself
//  exampleNetworkManagerUsage();

  _display << "Type (q) to quit" << endl;

  for (QString selection{_input.read(1)}; selection.toLower() != "q"; selection = _input.read(1)) {

    if (selection != '\n') {
      _display << "typed something" << selection << endl;
      _input.readLine(); // skip the rest of the line
    }
  }

  // Need to exit the event loop to end the application
  QCoreApplication::instance()->quit();
}



