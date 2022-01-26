#pragma once
#include "IUser.h"
#include <iostream>

using namespace std;

class Customer : public IUser
{
public:
	Customer(){}
	virtual void performOperation(IItem *item) {
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
	virtual void setItemRole(eAdminRoleHeader ieRole) {
		return;
	}
	virtual ~Customer(){}
};

