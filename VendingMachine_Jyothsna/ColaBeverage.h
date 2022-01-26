#pragma once
#include "IItem.h"

class ColaBeverage : public IItem
{
public:
	ColaBeverage() {
		iItemCount = 100;
		dItemPrice = 20.00;
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
	virtual ~ColaBeverage(){}
};