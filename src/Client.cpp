#include "Client.h"
#include <iostream>

Client::Client(int id, const std::string& firstName, const std::string& lastName, const std::string& password,
               const std::string& address, const std::string& phoneNumber)
    : Person(id, firstName, lastName, password), address(address), phoneNumber(phoneNumber) {}

std::string Client::getAddress() const {
    return address;
}

std::string Client::getPhoneNumber() const {
    return phoneNumber;
}

void Client::setAddress(const std::string& address) {
    this->address = address;
}

void Client::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Client::displayInfo() const {
    std::cout << "Client ID: " << id << "\n"
              << "Name: " << firstName << " " << lastName << "\n"
              << "Phone: " << phoneNumber << "\n"
              << "Address: " << address << "\n";
}
