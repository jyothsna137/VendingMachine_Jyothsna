#pragma once
#include "IItem.h"

class BarChocolate : public IItem
{
public:
	BarChocolate() {
		iItemCount = 100;
		dItemPrice = 50.00;
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
	virtual ~BarChocolate() {}
};