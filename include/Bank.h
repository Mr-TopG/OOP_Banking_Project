#ifndef BANK_H
#define BANK_H

#include "Client.h"
#include "Account.h"
#include "Transaction.h"
#include "Loan.h"
#include <vector>
#include <memory>
#include <string>

class Bank {
private:
    std::vector<Client> clients;
    std::vector<std::unique_ptr<Account>> accounts; // Store Abstract Accounts safely
    std::vector<Transaction> transactions;
    std::vector<Loan> loans;
    int nextClientId = 1;
    int nextAccountNumber = 1000;

public:
    Bank() = default;

    // Client Management
    void createClient(const std::string& firstName, const std::string& lastName, 
                      const std::string& password, const std::string& address, 
                      const std::string& phoneNumber);
    
    Client* getClient(int id);
    void displayAllClients() const;

    // Account Management
    void createCheckingAccount(int clientId, double initialBalance, double limit);
    void createSavingsAccount(int clientId, double initialBalance, double rate);
    void displayAllAccounts() const;
    
    // Financial Operations
    void displayTransactions() const;

    // Loan Management
    void requestLoan(int clientId, double principal, double rate);
    void payLoan(int loanId, double amount);
    void displayAllLoans() const;
    Account* getAccount(const std::string& accountNumber);
    void depositToAccount(const std::string& accountNumber, double amount);
    void withdrawFromAccount(const std::string& accountNumber, double amount);
    void transfer(const std::string& fromAccount, const std::string& toAccount, double amount);
};

#endif // BANK_H
