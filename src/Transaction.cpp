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

void Transaction::displayTransaction() const {
    std::cout << "[" << timestamp << "] ID: " << transactionId 
              << " | " << type << " | Amount: $" << amount 
              << " | Account: " << sourceAccount;
    if (!destAccount.empty()) {
        std::cout << " -> " << destAccount;
    }
    std::cout << "\n";
}
