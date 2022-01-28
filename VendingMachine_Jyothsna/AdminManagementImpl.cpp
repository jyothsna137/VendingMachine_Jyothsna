#include "pch.h"
#include "AdminManagementImpl.h"
#include <iostream>
#include <string>

using namespace std;

bool AdminManagementImpl::manageUserActivity()
{
	if (checkAdminPassCode()) {
		eAdminRoleHeader enumAdminRole = (eAdminRoleHeader)displayAdminPrimaryOptions();
		return performAdminOperation((eItemCategoryHeader)displayAdminSecondaryOptions(enumAdminRole), enumAdminRole);
	}
	else {
		cout << "Unauthorized user";
		return false;
	}		
}

bool AdminManagementImpl::checkAdminPassCode() {
	int iCount = 3;
	string strpassCode;
	cout << "Enter Passcode" << endl;
	do {
		cin >> strpassCode;
		if (0 != strpassCode.compare("1234")) {
			cout << "Invalid Code. " << "You have " << --iCount << " attempt(s) left" << endl;
		}
	} while ((0 != strpassCode.compare("1234") && (iCount > 0)));
	if (0 == strpassCode.compare("1234")) { return true; }
	return false;
}

int AdminManagementImpl::displayAdminPrimaryOptions() {
	int iUserOption = -1;
	cout << "Welcome Admin!!" << endl << "Please enter an option from the following" << endl;
	cout << "1. Add Item" << endl << "2. Modify Price" << endl;
	do {
		cin >> iUserOption;
		if ((iUserOption < 1) || (iUserOption > 2)) {
			cout << "Please enter a valid option" << endl;
		}
	} while (((iUserOption < 1) || (iUserOption > 2)));
	return iUserOption;
}

int AdminManagementImpl::displayAdminSecondaryOptions(int ipAdminRole) {
	int iUserOption = -1;
	if (ipAdminRole == 1) {
		cout << "1. Add Beverage Cola" << endl << "2. Add Package Chips" << endl << "3. Add Chocolate Bar" << endl;
	}
	else if (ipAdminRole == 2) {
		cout << "1. Change Price of Beverage Cola" << endl << "2. Change Price of Package Chips" << endl << "3. Change Price of Chocolate Bar" << endl;
	}
	do {
		cin >> iUserOption;
		if ((iUserOption < 1) || (iUserOption > 3)) {
			cout << "Please enter a valid option" << endl;
		}
	} while ((iUserOption < 1) || (iUserOption > 3));
	return iUserOption;
}
bool AdminManagementImpl::performAdminOperation(eItemCategoryHeader ipEnumItemCategory, eAdminRoleHeader ipEnumAdminRole) {
	//Initialization
	unique_ptr<UserFactory> sptrObjUserFact(new UserFactory());
	unique_ptr<ItemFactory> sptrObjItemFact(new ItemFactory());
	unique_ptr<AbstractUser> sptrAdmin(sptrObjUserFact.get()->getUserCategory(eUserCategoryHeader::AdminUser));
	unique_ptr<ItemInterface> sptrItem(sptrObjItemFact.get()->getItemCategory(ipEnumItemCategory));

	sptrAdmin.get()->setItemRole(ipEnumAdminRole);
	sptrAdmin.get()->performOperation(sptrItem.get());

	return true;
}
AdminManagementImpl::~AdminManagementImpl()
{
}
