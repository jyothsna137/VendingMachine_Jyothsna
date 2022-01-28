#include "pch.h"
#include "UserFactory.h"
#include "AdminImpl.h"
#include "CustomerImpl.h"

AbstractUser* UserFactory::getUserCategory(eUserCategoryHeader enumUserType) {
	if (enumUserType == eUserCategoryHeader::CustomerUser) {
		return new CustomerImpl();
	}
	else if (enumUserType == eUserCategoryHeader::AdminUser) {
		return new AdminImpl();
	}
	return nullptr;
}
