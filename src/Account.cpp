#include "Account.h"
#include <iostream>

Account::Account(const std::string& accountNumber, int clientId, double initialBalance)
    : accountNumber(accountNumber), clientId(clientId), balance(initialBalance) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getClientId() const {
    return clientId;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Successfully deposited $" << amount << " into account " << accountNumber << ".\n";
        std::cout << "New balance: $" << balance << "\n";
    } else {
        std::cout << "Invalid deposit amount. Must be greater than 0.\n";
    }
}
