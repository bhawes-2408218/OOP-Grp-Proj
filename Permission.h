#pragma once
#include <iostream>
#include <string>
#include "Permission.h"

class Permission {
private: 
std:: string permission;
stdd:: string description;

public:
Permission () = default ;
Permission (const std::string& perm, const std::string& desc)
: permission(perm) , description(desc){}

std::string getPermission() const {return permission; }
std::string getDescription() const {return description} 

void setPermission(const std::string& perm) {permission = perm }
void setDescription(const std::string& desc) {description = desc}
;

