#pragma once
#include <iostream>
#include <string>
#include "UserRepository.h"
#include "Audit.h"
#include "User.h"
using namespace std;

class UserManagement {
	private:
		UserRepository UserRepo;
		Audit audit;

	public:
		UserManagement() {
			
		}

		UserManagement(const UserManagement &usermgmt) {
			
		}

		

		
};