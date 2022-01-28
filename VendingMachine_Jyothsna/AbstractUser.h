#pragma once
#include "ItemInterface.h"
class AbstractUser
{
public:
	virtual ~AbstractUser(){}
	virtual void performOperation(ItemInterface *item) = 0;
	virtual void setItemRole(eAdminRoleHeader ieRole) { return; }
};

