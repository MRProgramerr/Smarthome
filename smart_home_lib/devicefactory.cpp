#include "devicefactory.h"

DeviceFactory::DeviceFactory()
{

}

Device *DeviceFactory::createDevice(DeviceAbstractFactory *daf)
{
    return daf->createDevice();
}
