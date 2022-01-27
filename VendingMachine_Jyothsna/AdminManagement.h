#pragma once
#include "UserManagementSection.h"
class AdminManagement : public UserManagementSection
{
public:
	virtual bool manageUserActivity();
	virtual ~AdminManagement();

private:
	bool checkAdminPassCode();
	int displayAdminPrimaryOptions();
	int displayAdminSecondaryOptions(int eRole);
	bool performAdminOperation(eItemCategoryHeader eItemCategory, eAdminRoleHeader eAdminRole);
};

