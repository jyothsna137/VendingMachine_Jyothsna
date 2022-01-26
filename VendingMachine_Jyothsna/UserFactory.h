#pragma once
#include "CategoryDef.h"
#include "IUser.h"
class UserFactory
{
public:
	static IUser* getUserCategory(eUserCategoryHeader eItem);
};

