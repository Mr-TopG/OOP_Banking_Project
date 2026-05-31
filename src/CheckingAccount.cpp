#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string& accountNumber, int clientId, double initialBalance, double limit)
    : Account(accountNumber, clientId, initialBalance), overdraftLimit(limit) {}

double CheckingAccount::getOverdraftLimit() const { return overdraftLimit; }

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        std::cout << "Successfully withdrew $" << amount << ". New balance is $" << balance << "\n";
        return true;
    } else {
        std::cout << "Withdrawal failed: Overdraft limit exceeded.\n";
        return false;
    }
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Account Type: Checking\n"
              << "Account Number: " << accountNumber << "\n"
              << "Client ID: " << clientId << "\n"
              << "Balance: $" << balance << "\n"
              << "Overdraft Limit: $" << overdraftLimit << "\n";
}
