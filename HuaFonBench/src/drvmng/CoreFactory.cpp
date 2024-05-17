#include "CoreFactory.h"
#include <CanBusIface.h>
#include "UartBusIface.h"
CoreFactory::CoreFactory()
{

}

CoreFactory::~CoreFactory()
{}

CommonIface* CoreFactory::creatIfClass(CORETYPE type)
{
    //if (type == TypeCanBusIface)
    //    return new UartBusIface(NULL);
    //else if (type == TypeEthBusIface)
    //    return new UartBusIface(NULL);
    //else if (type == TypeUartBusIface)
    //    return new UartBusIface(NULL);
	return nullptr;
}
