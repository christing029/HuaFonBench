#pragma once
#ifndef CoreFactory_H
#define CoreFactory_H
#include <src/drvmng/CommonIface.h>
class CoreFactory 
{
public:
	CoreFactory();
	~CoreFactory();
public :
	CommonIface* creatIfClass(CORETYPE type);
};
#endif