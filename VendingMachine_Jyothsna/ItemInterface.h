#pragma once
#include "CategoryDef.h"
class ItemInterface
{
protected:
	int m_iItemCount;
	double m_dItemPrice;

public:
	virtual int getItemCount() = 0;
	virtual double getItemPrice() = 0;
	virtual void setItemCount(int ipitemCount) = 0;
	virtual void setItemPrice(double dItemPrice) = 0;

	virtual ~ItemInterface(){}
};

