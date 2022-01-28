#include "pch.h"
#include "ColaBeverageImpl.h"
#include "BarChocolateImpl.h"
#include "ChipsPacketImpl.h"

ItemInterface* ItemFactory::getItemCategory(eItemCategoryHeader eItem) {
	if (eItem == eItemCategoryHeader::BeverageCola) {
		return new ColaBeverageImpl();
	}
	else if (eItem == eItemCategoryHeader::ChocolateBar) {
		return new BarChocolateImpl();
	}
	else if (eItem == eItemCategoryHeader::PackageChips) {
		return new ChipsPacketImpl();
	}
	return nullptr;
}

