#include "pch.h"
#include "UserFactory.h"
#include "Admin.h"
#include "Customer.h"

IUser* UserFactory::getUserCategory(eUserCategoryHeader eUser) {
	if (eUser == eUserCategoryHeader::CustomerUser) {
		return new Customer();
	}
	else if (eUser == eUserCategoryHeader::AdminUser) {
		return new Admin();
	}
	return nullptr;
}
