#include "Admin.h"
#include <iostream>

Admin::Admin(int id, const std::string& firstName, const std::string& lastName, const std::string& password, const std::string& role)
    : Person(id, firstName, lastName, password), role(role) {}

std::string Admin::getRole() const {
    return role;
}

void Admin::setRole(const std::string& role) {
    this->role = role;
}

void Admin::displayInfo() const {
    std::cout << "Admin ID: " << id << "\n"
              << "Name: " << firstName << " " << lastName << "\n"
              << "Role: " << role << "\n";
}
