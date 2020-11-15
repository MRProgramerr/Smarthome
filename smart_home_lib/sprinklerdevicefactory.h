#ifndef SPRINKLERDEVICEFACTORY_H
#define SPRINKLERDEVICEFACTORY_H
#include "deviceabstractfactory.h"

/**
 * @brief The SprinklerDeviceFactory class
 * A concrete factory for creating sprinkler devices
 */

class SprinklerDeviceFactory : public DeviceAbstractFactory
{
public:

    /**
     * @brief SprinklerDeviceFactory
     * The constructor for the SprinklerDeviceFactory
     * @param name
     */
      SprinklerDeviceFactory(QString name);

      /**
       * @brief createDevice
       * @return A sprinkler object
       */
      Device *createDevice();

private:
      QString _name;

};

#endif // SPRINKLERDEVICEFACTORY_H
