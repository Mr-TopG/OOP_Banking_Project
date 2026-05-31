#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

Bank::Bank() {
    // Initialize a default system admin so we can login later
    createAdmin("System", "Admin", "admin123", "Root");
}

void Bank::createAdmin(const std::string& firstName, const std::string& lastName, 
                       const std::string& password, const std::string& role) {
    Admin newAdmin(nextAdminId++, firstName, lastName, password, role);
    admins.push_back(newAdmin);
    std::cout << "Admin " << firstName << " " << lastName << " created successfully with ID: " << newAdmin.getId() << "\n";
}

Admin* Bank::authenticateAdmin(int id, const std::string& password) {
    for (auto& admin : admins) {
        if (admin.getId() == id && admin.getPassword() == password) {
            return &admin;
        }
    }
    return nullptr;
}

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
    if (sender->withdraw(amount)) {
        // If withdrawal is successful, deposit to receiver
        receiver->deposit(amount);
        transactions.emplace_back("TRANSFER", amount, fromAccount, toAccount);
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
        loan.displayLoanInfo();
    }
}

void Bank::saveData() const {
    std::ofstream out("bank_data.txt");
    if (!out) {
        std::cout << "Error opening file to save data.\n";
        return;
    }
    
    // Save Clients
    out << clients.size() << "\n";
    for (const auto& c : clients) {
        out << c.getId() << "," << c.getFirstName() << "," << c.getLastName() << "," 
            << c.getPassword() << "," << c.getAddress() << "," << c.getPhoneNumber() << "\n";
    }

    // Save Accounts (Identifying typings)
    out << accounts.size() << "\n";
    for (const auto& acc : accounts) {
        if (auto* chk = dynamic_cast<CheckingAccount*>(acc.get())) {
            out << "CHK," << chk->getAccountNumber() << "," << chk->getClientId() << "," 
                << chk->getBalance() << "," << chk->getOverdraftLimit() << "\n";
        } else if (auto* sav = dynamic_cast<SavingsAccount*>(acc.get())) {
            out << "SAV," << sav->getAccountNumber() << "," << sav->getClientId() << "," 
                << sav->getBalance() << "," << sav->getInterestRate() << "\n";
        }
    }

    // Save Loans
    out << loans.size() << "\n";
    for (const auto& ln : loans) {
        out << ln.getLoanId() << "," << ln.getClientId() << "," << ln.getPrincipal() << "," 
            << ln.getInterestRate() << "," << ln.getRemainingBalance() << "\n";
    }
    
    // Save Transactions
    out << transactions.size() << "\n";
    for (const auto& tx : transactions) {
        out << tx.getTransactionId() << "," << tx.getType() << "," << tx.getAmount() << "," 
            << tx.getTimestamp() << "," << tx.getSourceAccount() << "," 
            << (tx.getDestAccount().empty() ? "NONE" : tx.getDestAccount()) << "\n";
    }
    
    out.close();
    std::cout << "Data saved successfully to bank_data.txt\n";
}

void Bank::loadData() {
    std::ifstream in("bank_data.txt");
    if (!in) {
        std::cout << "No existing bank_data.txt found. Starting fresh.\n";
        return;
    }
    
    clients.clear();
    accounts.clear();
    loans.clear();
    transactions.clear();
    
    std::string line;
    int size;

    // Load Clients
    if (in >> size) {
        in.ignore();
        for (int i = 0; i < size; ++i) {
            std::getline(in, line);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss, token, ',')) tokens.push_back(token);
            if (tokens.size() == 6) {
                clients.emplace_back(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);
                if (std::stoi(tokens[0]) >= nextClientId) nextClientId = std::stoi(tokens[0]) + 1;
            }
        }
    }

    // Load Accounts
    if (in >> size) {
        in.ignore();
        for (int i = 0; i < size; ++i) {
            std::getline(in, line);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss, token, ',')) tokens.push_back(token);
            if (tokens.size() >= 5) {
                if (tokens[0] == "CHK") {
                    accounts.push_back(std::make_unique<CheckingAccount>(tokens[1], std::stoi(tokens[2]), std::stod(tokens[3]), std::stod(tokens[4])));
                } else if (tokens[0] == "SAV") {
                    accounts.push_back(std::make_unique<SavingsAccount>(tokens[1], std::stoi(tokens[2]), std::stod(tokens[3]), std::stod(tokens[4])));
                }
            }
        }
    }

    // Load Loans
    if (in >> size) {
        in.ignore();
        for (int i = 0; i < size; ++i) {
            std::getline(in, line);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss, token, ',')) tokens.push_back(token);
            if (tokens.size() == 5) {
                loans.emplace_back(std::stoi(tokens[0]), std::stoi(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3]), std::stod(tokens[4]));
            }
        }
    }

    // Load Transactions
    if (in >> size) {
        in.ignore();
        for (int i = 0; i < size; ++i) {
            std::getline(in, line);
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while(std::getline(ss, token, ',')) tokens.push_back(token);
            if (tokens.size() == 6) {
                std::string dest = tokens[5] == "NONE" ? "" : tokens[5];
                transactions.emplace_back(std::stoi(tokens[0]), tokens[1], std::stod(tokens[2]), tokens[3], tokens[4], dest);
            }
        }
    }
    
    in.close();
    std::cout << "Data loaded successfully from bank_data.txt\n";
}
