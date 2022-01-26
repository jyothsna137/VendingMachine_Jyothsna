#pragma once
#include "IUser.h"
#include "ItemFactory.h"
#include <iostream>

using namespace std;

class Admin : public IUser
{
	eAdminRoleHeader eRole;
public:
	Admin(){}
	virtual void performOperation(IItem *item) {

		int quantity;
		double price;
		if (item == nullptr) { return; }

		if (eRole == eAdminRoleHeader::ModifyQuantity) {
			cout << "Enter the quantity to be added" << endl;
			cin >> quantity;
			item->setItemCount(item->getItemCount() + quantity);
			cout << "Current Quantity:" << item->getItemCount() << endl;
		}
		else if (eRole == eAdminRoleHeader::ModifyPrice) {
			cout << "Enter the price of the item" << endl;
			cin >> price;
			item->setItemPrice(price);
			cout << "Price of the item set is Rs." << item->getItemPrice() << endl;
		}

	}
	virtual void setItemRole(eAdminRoleHeader ieRole) {
		eRole = ieRole;
	}

	virtual ~Admin(){}
};

