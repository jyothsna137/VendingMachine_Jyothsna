#pragma once
#include "IItem.h"
class IUser
{
public:
	virtual void performOperation(IItem *item) = 0;
	virtual void setItemRole(eAdminRoleHeader ieRole) { return; }
};

