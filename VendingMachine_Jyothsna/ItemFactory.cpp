#include "pch.h"
#include "ColaBeverage.h"
#include "BarChocolate.h"
#include "ChipsPacket.h"

IItem* ItemFactory::getItemCategory(eItemCategoryHeader eItem) {
	if (eItem == eItemCategoryHeader::BeverageCola) {
		return new ColaBeverage();
	}
	else if (eItem == eItemCategoryHeader::ChocolateBar) {
		return new BarChocolate();
	}
	else if (eItem == eItemCategoryHeader::PackageChips) {
		return new ChipsPacket();
	}
	return nullptr;
}

