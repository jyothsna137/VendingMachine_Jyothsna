#pragma once
#include "AbstractUser.h"
#include <iostream>

using namespace std;

class CustomerImpl final: public AbstractUser
{
public:
	CustomerImpl(){}
	virtual void performOperation(ItemInterface *item) override {
		int quantity;
		if (item == nullptr) { return; }

		cout << "Quantity available in the system :" << item->getItemCount() << endl;
		cout << "Price of the item is Rs." << item->getItemPrice() << endl;
		cout << "Enter the quantity required" << endl;
		do {
			cin >> quantity;
			if ((quantity < 1) || (quantity > item->getItemCount())) {
				cout << "Please enter a valid quantity" << endl;
			}
		} while ((quantity < 1) || (quantity > item->getItemCount()));

		cout << "Price you owe: Rs " << item->getItemPrice()*quantity << endl;
		item->setItemCount(item->getItemCount() - quantity);
		cout << "Current Quantity:" << item->getItemCount() << endl;

	}
	virtual void setItemRole(eAdminRoleHeader ieRole) override {
		return;
	}
	virtual ~CustomerImpl(){}
};

