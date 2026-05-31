#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string& accountNumber, int clientId, double initialBalance, double rate)
    : Account(accountNumber, clientId, initialBalance), interestRate(rate) {}

double SavingsAccount::getInterestRate() const { return interestRate; }

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Successfully withdrew $" << amount << ". New balance is $" << balance << "\n";
        return true;
    } else {
        std::cout << "Withdrawal failed: Insufficient funds in savings.\n";
        return false;
    }
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Account Type: Savings\n"
              << "Account Number: " << accountNumber << "\n"
              << "Client ID: " << clientId << "\n"
              << "Balance: $" << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::addInterest() {
    double interest = balance * (interestRate / 100.0);
    balance += interest;
    std::cout << "Interest added: $" << interest << ". New balance: $" << balance << "\n";
}
