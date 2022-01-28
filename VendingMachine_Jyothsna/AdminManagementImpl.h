#pragma once
#include "UserManagementInterface.h"
class AdminManagementImpl final: public UserManagementInterface
{
public:
	virtual bool manageUserActivity() override;
	virtual ~AdminManagementImpl();

private:
	bool checkAdminPassCode();
	int displayAdminPrimaryOptions();
	int displayAdminSecondaryOptions(int eRole);
	bool performAdminOperation(eItemCategoryHeader eItemCategory, eAdminRoleHeader eAdminRole);
};

