#include <iostream>

#include "Bank.h"

void displayMenu() {
    std::cout << "\n=== Banking System ===\n";
    std::cout << "1. Admin: Create Client\n";
    std::cout << "2. Admin: View All Clients\n";
    std::cout << "3. Admin: Create Checking Account\n";
    std::cout << "4. Admin: Create Savings Account\n";
    std::cout << "5. Client: Deposit to Account\n";
    std::cout << "6. Client: Withdraw from Account\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void handleCreateClient(Bank& bank) {
    std::string first, last, pass, addr, phone;
    std::cout << "Enter First Name: ";
    std::cin >> first;
    std::cout << "Enter Last Name: ";
    std::cin >> last;
    std::cout << "Enter Password: ";
    std::cin >> pass;
    std::cout << "Enter Address: ";
    std::cin.ignore(); // clear newline buffer
    std::getline(std::cin, addr);
    std::cout << "Enter Phone Number: ";
    std::cin >> phone;

    bank.createClient(first, last, pass, addr, phone);
}

void handleCreateChecking(Bank& bank) {
    int clientId;
    double initialBalance, limit;
    std::cout << "Enter Client ID: ";
    std::cin >> clientId;
    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;
    std::cout << "Enter Overdraft Limit: ";
    std::cin >> limit;
    bank.createCheckingAccount(clientId, initialBalance, limit);
}

void handleCreateSavings(Bank& bank) {
    int clientId;
    double initialBalance, rate;
    std::cout << "Enter Client ID: ";
    std::cin >> clientId;
    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;
    std::cout << "Enter Interest Rate (%): ";
    std::cin >> rate;
    bank.createSavingsAccount(clientId, initialBalance, rate);
}

void handleDeposit(Bank& bank) {
    std::string accountNumber;
    double amount;
    std::cout << "Enter Account Number (e.g., CHK1000 or SAV1001): ";
    std::cin >> accountNumber;
    std::cout << "Enter Amount to Deposit: ";
    std::cin >> amount;
    bank.depositToAccount(accountNumber, amount);
}

void handleWithdraw(Bank& bank) {
    std::string accountNumber;
    double amount;
    std::cout << "Enter Account Number (e.g., CHK1000 or SAV1001): ";
    std::cin >> accountNumber;
    std::cout << "Enter Amount to Withdraw: ";
    std::cin >> amount;
    bank.withdrawFromAccount(accountNumber, amount);
}

int main() {
    Bank myBank;
    int choice = -1;
    
    std::cout << "Initializing Banking System...\n";
    
    while (choice != 0) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = -1;
        }
        
        switch (choice) {
            case 1:
                handleCreateClient(myBank);
                break;
            case 2:
                myBank.displayAllClients();
                break;
            case 3:
                handleCreateChecking(myBank);
                break;
            case 4:
                handleCreateSavings(myBank);
                break;
            case 5:
                handleDeposit(myBank);
                break;
            case 6:
                handleWithdraw(myBank);
                break;
            case 0:
                std::cout << "Exiting system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
