// VendingMachine_Jyothsna.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "CustomerManagementImpl.h"
#include "AdminManagementImpl.h"

using namespace std;

int main()
{
	int iUserCategory = -1;
	unique_ptr<UserManagementInterface> sptrObjUserMgmt;
	
	cout << "******Welcome to Star Vending Machine!!!!******" << endl << endl;
	cout << "Please enter an option from the following options:-" << endl << endl;
	cout << "1. Customer " << endl <<"2. Admin "<<endl;
	do{
		cin >> iUserCategory;
		if (iUserCategory == 1)
		{
			sptrObjUserMgmt.reset(new CustomerManagementImpl());
		}
		else if (iUserCategory == 2) {
			sptrObjUserMgmt.reset(new AdminManagementImpl());
		}
		else {
			cout << "Please enter a valid option" << endl;
		}
	} while ((iUserCategory < 1) || (iUserCategory > 2));

	if (nullptr != sptrObjUserMgmt) {
		sptrObjUserMgmt.get()->manageUserActivity();
	}	
	_getch();
	return 0;
}
