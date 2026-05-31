#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accountNumber, int clientId, double initialBalance, double rate);
    
    // Getters
    double getInterestRate() const;

    // Financial operations implementations
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
    
    void addInterest(); // Specific to savings
};

#endif // SAVINGS_ACCOUNT_H
