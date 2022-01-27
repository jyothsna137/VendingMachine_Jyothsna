#include "pch.h"
#include "CustomerManagement.h"
#include <iostream>

using namespace std;

bool CustomerManagement::manageUserActivity()
{
	return performCustomerOperation((eItemCategoryHeader)displayCustomerOptions());
}
CustomerManagement::~CustomerManagement()
{
}

int CustomerManagement::displayCustomerOptions()
{
	int userOption = -1;
	cout << "Welcome User!!" << endl << "Please enter an option from the following" << endl;
	cout << "1. Dispense Beverage Cola" << endl << "2. Dispense Package Chips" << endl << "3. Dispense Chocolate Bar" << endl;
	do {
		cin >> userOption;
		if ((userOption < 1) || (userOption > 3)) {
			cout << "Enter a valid option" << endl;
		}
	} while ((userOption < 1) || (userOption > 3));
	return userOption;
}
bool CustomerManagement::performCustomerOperation(eItemCategoryHeader eItemCategory) {

	UserFactory *userFact = new UserFactory();
	ItemFactory *itemFact = new ItemFactory();
	IUser *user = userFact->getUserCategory(eUserCategoryHeader::CustomerUser);
	IItem *item = itemFact->getItemCategory(eItemCategory);

	user->performOperation(item);

	delete item;
	delete user;
	delete itemFact;
	delete userFact;

	return true;
}
