#pragma once
#include "UserManagementSection.h"
class CustomerManagement :
	public UserManagementSection
{
public:
	virtual ~CustomerManagement();
	virtual bool manageUserActivity();

private:
	int displayCustomerOptions();
	bool performCustomerOperation(eItemCategoryHeader eItemCategory);
};

