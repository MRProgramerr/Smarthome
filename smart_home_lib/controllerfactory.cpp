#include "controllerfactory.h"
#include "device.h"
#include "controller.h"

ControllerFactory::ControllerFactory(QString name) : _name(name)
{

}


Device *ControllerFactory::createDevice()
{
    return new Controller(_name);
}

