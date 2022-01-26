// VendingMachine_Jyothsna.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int displayCustomerOptions() {
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
bool checkAdminPassCode() {
	int count = 4;
	string passCode;
	cout << "Enter Passcode" << endl;
	do {
		cin >> passCode;
		if (0 != passCode.compare("1234")) {
			cout << "Invalid Code. " <<"You have "<< --count<<" attempts left"<<endl;
		}
	} while ((0 != passCode.compare("1234")&&(count > 0)));
	if (0 == passCode.compare("1234")) { return true; }
	return false;
}
int displayAdminPrimaryOptions() {
	int userOption = -1;
	cout << "Welcome Admin!!" << endl << "Please enter an option from the following" << endl;
	cout << "1. Add Item" << endl << "2. Modify Price" << endl;
	do {
		cin >> userOption;
		if ((userOption < 1) || (userOption > 2)) {
			cout << "Enter a valid option"<<endl;
		}
	} while (((userOption < 1) || (userOption > 2)));
	return userOption;
}

int displayAdminSecondaryOptions(int eRole) {
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
			cout << "Enter a valid option"<<endl;
		}
	} while ((userOption < 1) || (userOption > 3));
	return userOption;
}

bool performUserOperation(eUserCategoryHeader eUserCategory, eItemCategoryHeader eItemCategory, eAdminRoleHeader eAdminRole) {
	UserFactory *userFact = new UserFactory();
	ItemFactory *itemFact = new ItemFactory();
	IUser *user = userFact->getUserCategory(eUserCategory);
	IItem *item = itemFact->getItemCategory(eItemCategory);

	user->setItemRole(eAdminRole);
	user->performOperation(item);

	delete item;
	delete user;
	delete itemFact;
	delete userFact;

	return true;
}
int main()
{
	int userCategory, userOption, adminRole = -1;
	
	cout << "Welcome to Star Vending Machine" << endl;
	cout << "Please enter the following options" << endl;
	cout << "1. Customer " << endl <<"2. Admin "<<endl;
	do{
		cin >> userCategory;
		if (userCategory == 1)
		{
			userOption = displayCustomerOptions();
			performUserOperation((eUserCategoryHeader)userCategory, (eItemCategoryHeader)userOption, (eAdminRoleHeader)adminRole);
		}
		else if(userCategory == 2) {
			if (checkAdminPassCode()) {
				adminRole = displayAdminPrimaryOptions();
				userOption = displayAdminSecondaryOptions(adminRole);
				performUserOperation((eUserCategoryHeader)userCategory, (eItemCategoryHeader)userOption, (eAdminRoleHeader)adminRole);
			}
			else {
				cout << "Unauthorized user";
				return 0;
			}
		}
		else if ((userCategory < 1) || (userCategory > 2)) {
			cout << "Enter a valid option" << endl;
		}
	} while ((userCategory < 1) || (userCategory > 2));
	return 0;
}
