#ifndef CONTROLLERFACTORY_H
#define CONTROLLERFACTORY_H

#include "deviceabstractfactory.h"

/**
 * @brief The ControllerFactory class
 * The concrete factory class for creating
 * controller objects according to the
 * abstract factory pattern
 */

class ControllerFactory: public DeviceAbstractFactory
{
public:

    /**
     * @brief ControllerFactory
     * The constructor for the controller factory class
     * @param name
     */
    ControllerFactory(QString name);

    /**
     * @brief createDevice
     * The createDevice function creates the
     * concrete controller object
     * @return A concrete controller object
     */
    Device *createDevice();

private:
    QString _name;
};

#endif // CONTROLLERFACTORY_H
