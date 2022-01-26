#pragma once
#include "CategoryDef.h"
class IItem
{
protected:
	int iItemCount;
	double dItemPrice;

public:
	virtual int getItemCount() = 0;
	virtual double getItemPrice() = 0;
	virtual void setItemCount(int ipitemCount) = 0;
	virtual void setItemPrice(double dItemPrice) = 0;

	virtual ~IItem(){}
};

