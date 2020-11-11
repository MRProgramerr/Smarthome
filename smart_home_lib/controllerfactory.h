#ifndef CONTROLLERFACTORY_H
#define CONTROLLERFACTORY_H

#include "deviceabstractfactory.h"

class ControllerFactory: public DeviceAbstractFactory
{
public:
    ControllerFactory(QString name);

    Device *createDevice();

private:
    QString _name;
};

#endif // CONTROLLERFACTORY_H
