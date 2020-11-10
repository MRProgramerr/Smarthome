#include "controller.h"

Controller::Controller(QString name)  : Device(name)
{

    std::vector<ProxyInterface*> s;
    LightSwitchProxy l("Karan");

   s.push_back(&l);


   for(auto elem : s){
       std::cout << elem->realDevice()->getDeviceName().toUtf8().constData();
   }



}
