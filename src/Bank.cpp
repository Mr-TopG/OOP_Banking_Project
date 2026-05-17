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
    } else {
        std::cout << "Error: Account number " << accountNumber << " not found.\n";
    }
}

void Bank::withdrawFromAccount(const std::string& accountNumber, double amount) {
    Account* acc = getAccount(accountNumber);
    if (acc) {
        acc->withdraw(amount); // This uses dynamic polymorphism to call the correct withdraw logic
    } else {
        std::cout << "Error: Account number " << accountNumber << " not found.\n";
    }
}
