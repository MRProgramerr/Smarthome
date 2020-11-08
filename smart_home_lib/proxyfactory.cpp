#include "proxyfactory.h"

ProxyFactory::ProxyFactory()
{

}

ProxyInterface* ProxyFactory::createProxy(ProxyAbstractFactory* paf)
{
    return paf->createProxy();
}
