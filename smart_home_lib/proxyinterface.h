#ifndef PROXYINTERFACE_H
#define PROXYINTERFACE_H
#include "device.h"


class ProxyInterface
{
public:
    ProxyInterface();
    virtual ~ProxyInterface(){};
    virtual Device* realDevice() = 0;

};

#endif // PROXYINTERFACE_H
