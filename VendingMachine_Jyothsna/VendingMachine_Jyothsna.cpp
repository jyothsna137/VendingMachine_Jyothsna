// VendingMachine_Jyothsna.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "CustomerManagement.h"
#include "AdminManagement.h"

using namespace std;

int main()
{
	int userCategory;
	UserManagementSection *userMgmt = nullptr;
	
	cout << "Welcome to Star Vending Machine" << endl;
	cout << "Please enter the following options" << endl;
	cout << "1. Customer " << endl <<"2. Admin "<<endl;
	do{
		cin >> userCategory;
		if (userCategory == 1)
		{
			userMgmt = new CustomerManagement();
		}
		else if (userCategory == 2) {
			userMgmt = new AdminManagement();
		}
		else {
			cout << "Enter a valid option" << endl;
		}
	} while ((userCategory < 1) || (userCategory > 2));

	if (nullptr != userMgmt) {
		userMgmt->manageUserActivity();
		delete userMgmt;
	}
	
	_getch();
	return 0;
}
