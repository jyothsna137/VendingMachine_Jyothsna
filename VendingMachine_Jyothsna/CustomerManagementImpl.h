#pragma once
#include "UserManagementInterface.h"

class CustomerManagementImpl final:public UserManagementInterface
{
public:
	virtual ~CustomerManagementImpl();
	virtual bool manageUserActivity() override;

private:
	int displayCustomerOptions();
	bool performCustomerOperation(eItemCategoryHeader eItemCategory);
};

