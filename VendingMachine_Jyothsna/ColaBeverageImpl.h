#pragma once
#include "ItemInterface.h"

class ColaBeverageImpl final: public ItemInterface
{
public:
	ColaBeverageImpl() {
		m_iItemCount = 100;
		m_dItemPrice = 20.00;
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
	virtual ~ColaBeverageImpl(){}
};