#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    static int nextTransactionId;
    int transactionId;
    std::string type; // "DEPOSIT", "WITHDRAWAL", "TRANSFER"
    double amount;
    std::string timestamp;
    std::string sourceAccount;
    std::string destAccount;

public:
    Transaction(const std::string& type, double amount, const std::string& sourceAccount, const std::string& destAccount = "");
    
    void displayTransaction() const;
};

#endif // TRANSACTION_H
