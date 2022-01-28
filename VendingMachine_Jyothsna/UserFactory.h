#pragma once
#include "CategoryDef.h"
#include "AbstractUser.h"
class UserFactory
{
public:
	static AbstractUser* getUserCategory(eUserCategoryHeader enumUserType);
};

