#pragma once
#include "ItemInterface.h"

class BarChocolateImpl final: public ItemInterface
{
public:
	BarChocolateImpl() {
		m_iItemCount = 100;
		m_dItemPrice = 50.00;
	}
	virtual int getItemCount() override {
		return m_iItemCount;
	}
	virtual double getItemPrice() override {
		return m_dItemPrice;
	}
	virtual void setItemCount(int itemCount) override {
		m_iItemCount = itemCount;
	}
	virtual void setItemPrice(double itemPrice) override {
		m_dItemPrice = itemPrice;
	}
	virtual ~BarChocolateImpl() {}
};