#pragma once
#include "IItem.h"

class ChipsPacket : public IItem
{
public:
	ChipsPacket() {
		iItemCount = 200;
		dItemPrice = 30.00;
	}
	virtual int getItemCount() {
		return iItemCount;
	}
	virtual double getItemPrice() {
		return dItemPrice;
	}
	virtual void setItemCount(int itemCount) {
		iItemCount = itemCount;
	}
	virtual void setItemPrice(double itemPrice) {
		dItemPrice = itemPrice;
	}
	virtual ~ChipsPacket() {}
};