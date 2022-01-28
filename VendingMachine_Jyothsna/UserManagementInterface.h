#pragma once
#include "CategoryDef.h"

class UserManagementInterface
{
public:
	virtual bool manageUserActivity() = 0;
	virtual ~UserManagementInterface() {}
};

