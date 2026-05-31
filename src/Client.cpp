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

const std::vector<std::string>& Client::getAccountNumbers() const {
    return accountNumbers;
}

const std::vector<int>& Client::getLoanIds() const {
    return loanIds;
}

void Client::setAddress(const std::string& address) {
    this->address = address;
}

void Client::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Client::addAccount(const std::string& accountNumber) {
    accountNumbers.push_back(accountNumber);
}

void Client::addLoan(int loanId) {
    loanIds.push_back(loanId);
}

void Client::displayInfo() const {
    std::cout << "Client ID: " << id << "\n"
              << "Name: " << firstName << " " << lastName << "\n"
              << "Phone: " << phoneNumber << "\n"
              << "Address: " << address << "\n";
    displayRelationships();
}

void Client::displayRelationships() const {
    std::cout << "Accounts: ";
    if (accountNumbers.empty()) {
        std::cout << "None";
    } else {
        for (const auto& acc : accountNumbers) {
            std::cout << acc << " ";
        }
    }
    std::cout << "\nLoans (IDs): ";
    if (loanIds.empty()) {
        std::cout << "None";
    } else {
        for (const auto& l : loanIds) {
            std::cout << l << " ";
        }
    }
    std::cout << "\n";
}
