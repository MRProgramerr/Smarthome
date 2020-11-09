#ifndef SPRINKLERSYSTEMPROXY_H
#define SPRINKLERSYSTEMPROXY_H

#include <QString>
#include "sprinklersystemproxyinterface.h"

class SprinklerSystemProxy : public SprinklerSystemProxyInterface
{
public:
    SprinklerSystemProxy(QString name);

    // Required functions overrides here
};

#endif // SPRINKLERSYSTEMPROXY_H
