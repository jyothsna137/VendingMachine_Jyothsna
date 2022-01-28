#pragma once
#include"CategoryDef.h"
#include "ItemInterface.h"

class ItemFactory
{
public:
	static ItemInterface* getItemCategory(eItemCategoryHeader eItem);
};

