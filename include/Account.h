#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string accountNumber;
    int clientId;
    double balance;

public:
    Account(const std::string& accountNumber, int clientId, double initialBalance = 0.0);
    virtual ~Account() = default; // Virtual destructor

    // Getters
    std::string getAccountNumber() const;
    int getClientId() const;
    double getBalance() const;

    // Financial operations
    virtual void deposit(double amount);
    
    // Pure virtual functions making Account abstract
    virtual bool withdraw(double amount) = 0; 
    virtual void displayAccountInfo() const = 0;
};

#endif // ACCOUNT_H
