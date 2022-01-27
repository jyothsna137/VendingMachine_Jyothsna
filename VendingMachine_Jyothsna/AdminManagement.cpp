#include "pch.h"
#include "AdminManagement.h"
#include <iostream>
#include <string>

using namespace std;

bool AdminManagement::manageUserActivity()
{
	if (checkAdminPassCode()) {
		eAdminRoleHeader adminRole = (eAdminRoleHeader)displayAdminPrimaryOptions();
		return performAdminOperation((eItemCategoryHeader)displayAdminSecondaryOptions(adminRole), adminRole);
	}
	else {
		cout << "Unauthorized user";
		return false;
	}		
}

bool AdminManagement::checkAdminPassCode() {
	int count = 3;
	string passCode;
	cout << "Enter Passcode" << endl;
	do {
		cin >> passCode;
		if (0 != passCode.compare("1234")) {
			cout << "Invalid Code. " << "You have " << --count << " attempts left" << endl;
		}
	} while ((0 != passCode.compare("1234") && (count > 0)));
	if (0 == passCode.compare("1234")) { return true; }
	return false;
}

int AdminManagement::displayAdminPrimaryOptions() {
	int userOption = -1;
	cout << "Welcome Admin!!" << endl << "Please enter an option from the following" << endl;
	cout << "1. Add Item" << endl << "2. Modify Price" << endl;
	do {
		cin >> userOption;
		if ((userOption < 1) || (userOption > 2)) {
			cout << "Enter a valid option" << endl;
		}
	} while (((userOption < 1) || (userOption > 2)));
	return userOption;
}

int AdminManagement::displayAdminSecondaryOptions(int eRole) {
	int userOption = -1;
	if (eRole == 1) {
		cout << "1. Add Beverage Cola" << endl << "2. Add Package Chips" << endl << "3. Add Chocolate Bar" << endl;
	}
	else if (eRole == 2) {
		cout << "1. Change Price of Beverage Cola" << endl << "2. Change Price of Package Chips" << endl << "3. Change Price of Chocolate Bar" << endl;
	}
	do {
		cin >> userOption;
		if ((userOption < 1) || (userOption > 3)) {
			cout << "Enter a valid option" << endl;
		}
	} while ((userOption < 1) || (userOption > 3));
	return userOption;
}
bool AdminManagement::performAdminOperation(eItemCategoryHeader eItemCategory, eAdminRoleHeader eAdminRole) {

	UserFactory *userFact = new UserFactory();
	ItemFactory *itemFact = new ItemFactory();
	IUser *user = userFact->getUserCategory(eUserCategoryHeader::AdminUser);
	IItem *item = itemFact->getItemCategory(eItemCategory);

	user->setItemRole(eAdminRole);
	user->performOperation(item);

	delete item;
	delete user;
	delete itemFact;
	delete userFact;

	return true;
}
AdminManagement::~AdminManagement()
{
}
