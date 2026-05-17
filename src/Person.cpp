#include "Person.h"

Person::Person(int id, const std::string& firstName, const std::string& lastName, const std::string& password)
    : id(id), firstName(firstName), lastName(lastName), password(password) {}

int Person::getId() const {
    return id;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

std::string Person::getPassword() const {
    return password;
}

void Person::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Person::setPassword(const std::string& password) {
    this->password = password;
}
