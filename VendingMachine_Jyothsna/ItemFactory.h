#pragma once
#include"CategoryDef.h"
#include "IItem.h"

class ItemFactory
{
public:
	static IItem* getItemCategory(eItemCategoryHeader eItem);
};

