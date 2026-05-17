#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const std::string& accountNumber, int clientId, double initialBalance, double limit);
    
    // Financial operations implementations
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};

#endif // CHECKING_ACCOUNT_H
