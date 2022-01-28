#include "pch.h"
#include "CustomerManagementImpl.h"
#include <iostream>

using namespace std;

bool CustomerManagementImpl::manageUserActivity()
{
	return performCustomerOperation((eItemCategoryHeader)displayCustomerOptions());
}
CustomerManagementImpl::~CustomerManagementImpl()
{
}

int CustomerManagementImpl::displayCustomerOptions()
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
bool CustomerManagementImpl::performCustomerOperation(eItemCategoryHeader eItemCategory) {
	//Initialization
	unique_ptr<UserFactory> sptrObjUserFact(new UserFactory());
	unique_ptr<ItemFactory> sptrObjItemFact(new ItemFactory());
	unique_ptr<AbstractUser> sptrCustomer(sptrObjUserFact.get()->getUserCategory(eUserCategoryHeader::CustomerUser));
	unique_ptr<ItemInterface> sptrItem(sptrObjItemFact.get()->getItemCategory(eItemCategory));

	sptrCustomer.get()->performOperation(sptrItem.get());

	return true;
}
