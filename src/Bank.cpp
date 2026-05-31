#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>

void Bank::createClient(const std::string& firstName, const std::string& lastName, 
                        const std::string& password, const std::string& address, 
                        const std::string& phoneNumber) {
    Client newClient(nextClientId++, firstName, lastName, password, address, phoneNumber);
    clients.push_back(newClient);
    std::cout << "Client " << firstName << " " << lastName << " created successfully with ID: " << newClient.getId() << "\n";
}

Client* Bank::getClient(int id) {
    for (auto& client : clients) {
        if (client.getId() == id) {
            return &client;
        }
    }
    return nullptr;
}

void Bank::displayAllClients() const {
    if (clients.empty()) {
        std::cout << "No clients registered in the bank.\n";
        return;
    }
    
    std::cout << "\n--- Bank Clients ---\n";
    for (const auto& client : clients) {
        client.displayInfo();
        std::cout << "--------------------\n";
    }
}

void Bank::createCheckingAccount(int clientId, double initialBalance, double limit) {
    if (getClient(clientId) != nullptr) {
        std::string accNum = "CHK" + std::to_string(nextAccountNumber++);
        accounts.push_back(std::make_unique<CheckingAccount>(accNum, clientId, initialBalance, limit));
        std::cout << "Checking Account created successfully: " << accNum << "\n";
    } else {
        std::cout << "Error: Client ID " << clientId << " not found.\n";
    }
}

void Bank::createSavingsAccount(int clientId, double initialBalance, double rate) {
    if (getClient(clientId) != nullptr) {
        std::string accNum = "SAV" + std::to_string(nextAccountNumber++);
        accounts.push_back(std::make_unique<SavingsAccount>(accNum, clientId, initialBalance, rate));
        std::cout << "Savings Account created successfully: " << accNum << "\n";
    } else {
        std::cout << "Error: Client ID " << clientId << " not found.\n";
    }
}

Account* Bank::getAccount(const std::string& accountNumber) {
    for (auto& acc : accounts) {
        if (acc->getAccountNumber() == accountNumber) {
            return acc.get();
        }
    }
    return nullptr;
}

void Bank::depositToAccount(const std::string& accountNumber, double amount) {
    Account* acc = getAccount(accountNumber);
    if (acc) {
        acc->deposit(amount);
        transactions.emplace_back("DEPOSIT", amount, accountNumber);
    } else {
        std::cout << "Error: Account number " << accountNumber << " not found.\n";
    }
}

void Bank::withdrawFromAccount(const std::string& accountNumber, double amount) {
    Account* acc = getAccount(accountNumber);
    if (acc) {
        if (acc->withdraw(amount)) { // This uses dynamic polymorphism to call the correct withdraw logic
            transactions.emplace_back("WITHDRAWAL", amount, accountNumber);
        }
    } else {
        std::cout << "Error: Account number " << accountNumber << " not found.\n";
    }
}

void Bank::displayAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts registered in the bank.\n";
        return;
    }
    std::cout << "\n--- Bank Accounts ---\n";
    for (const auto& acc : accounts) {
        acc->displayAccountInfo();
        std::cout << "---------------------\n";
    }
}

void Bank::transfer(const std::string& fromAccount, const std::string& toAccount, double amount) {
    if (amount <= 0) {
        std::cout << "Invalid transfer amount.\n";
        return;
    }
    
    Account* sender = getAccount(fromAccount);
    Account* receiver = getAccount(toAccount);
    
    if (!sender) {
        std::cout << "Sender account " << fromAccount << " not found.\n";
        return;
    }
    if (!receiver) {
        std::cout << "Receiver account " << toAccount << " not found.\n";
        return;
    }
    
    std::cout << "Initiating transfer of $" << amount << " from " << fromAccount << " to " << toAccount << "...\n";
    if (transactions.emplace_back("TRANSFER", amount, fromAccount, toAccount);
        std::cout << "Transfer complete.\n";
    } else {
        std::cout << "Transfer failed due to sender's withdrawal limits.\n";
    }
}

void Bank::displayTransactions() const {
    if (transactions.empty()) {
        std::cout << "No transactions recorded yet.\n";
        return;
    }
    std::cout << "\n--- Transaction History ---\n";
    for (const auto& tx : transactions) {
        tx.displayTransaction();
    }
}

void Bank::requestLoan(int clientId, double principal, double rate) {
    if (getClient(clientId) != nullptr) {
        loans.emplace_back(clientId, principal, rate);
        std::cout << "Loan approved and created for Client ID: " << clientId << ".\n";
    } else {
        std::cout << "Error: Client ID " << clientId << " not found.\n";
    }
}

void Bank::payLoan(int loanId, double amount) {
    for (auto& loan : loans) {
        if (loan.getLoanId() == loanId) {
            loan.makePayment(amount);
            return;
        }
    }
    std::cout << "Error: Loan ID " << loanId << " not found.\n";
}

void Bank::displayAllLoans() const {
    if (loans.empty()) {
        std::cout << "No active loans in the bank.\n";
        return;
    }
    std::cout << "\n--- Active Loans ---\n";
    for (const auto& loan : loans) {
        loan.displayLoanInfo()
        std::cout << "Transfer complete.\n";
    } else {
        std::cout << "Transfer failed due to sender's withdrawal limits.\n";
    }
}
