#include "Transaction.h"
#include <iostream>
#include <ctime>

int Transaction::nextTransactionId = 1;

Transaction::Transaction(const std::string& type, double amount, const std::string& sourceAccount, const std::string& destAccount)
    : transactionId(nextTransactionId++), type(type), amount(amount), sourceAccount(sourceAccount), destAccount(destAccount) {
    
    // Generate simple timestamp
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    timestamp = buf;
}

Transaction::Transaction(int id, const std::string& type, double amount, const std::string& timestamp, const std::string& sourceAccount, const std::string& destAccount)
    : transactionId(id), type(type), amount(amount), timestamp(timestamp), sourceAccount(sourceAccount), destAccount(destAccount) {
    if (id >= nextTransactionId) {
        nextTransactionId = id + 1;
    }
}

int Transaction::getTransactionId() const { return transactionId; }
std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getTimestamp() const { return timestamp; }
std::string Transaction::getSourceAccount() const { return sourceAccount; }
std::string Transaction::getDestAccount() const { return destAccount; }

void Transaction::displayTransaction() const {
    std::cout << "[" << timestamp << "] ID: " << transactionId 
              << " | " << type << " | Amount: $" << amount 
              << " | Account: " << sourceAccount;
    if (!destAccount.empty()) {
        std::cout << " -> " << destAccount;
    }
    std::cout << "\n";
}
