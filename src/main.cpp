#include <iostream>
#include "Bank.h"

void displayAdminMenu(Admin* admin) {
    std::cout << "\n=== Admin Panel [" << admin->getFirstName() << " " << admin->getLastName() << "] ===\n";
    std::cout << "1. Create Client\n";
    std::cout << "2. View All Clients\n";
    std::cout << "3. Create Checking Account\n";
    std::cout << "4. Create Savings Account\n";
    std::cout << "5. View All Accounts\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. View All Loans\n";
    std::cout << "0. Logout\n";
    std::cout << "Select an option: ";
}

void displayClientMenu() {
    std::cout << "\n=== Client Panel ===\n";
    std::cout << "1. Deposit to Account\n";
    std::cout << "2. Withdraw from Account\n";
    std::cout << "3. Transfer Funds\n";
    std::cout << "4. Request Loan\n";
    std::cout << "5. Pay Loan\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Select an option: ";
}

void displayMainMenu() {
    std::cout << "\n=== Main Menu ===\n";
    std::cout << "1. Admin Login\n";
    std::cout << "2. Client Operations\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

// Handler functions (kept mostly the same, removed from flat menu)
void handleCreateClient(Bank& bank) { /* Same as before */
    std::string first, last, pass, addr, phone;
    std::cout << "Enter First Name: "; std::cin >> first;
    std::cout << "Enter Last Name: "; std::cin >> last;
    std::cout << "Enter Password: "; std::cin >> pass;
    std::cout << "Enter Address: "; std::cin.ignore(); std::getline(std::cin, addr);
    std::cout << "Enter Phone Number: "; std::cin >> phone;
    bank.createClient(first, last, pass, addr, phone);
}

void handleCreateChecking(Bank& bank) {
    int clientId; double initialBalance, limit;
    std::cout << "Enter Client ID: "; std::cin >> clientId;
    std::cout << "Enter Initial Balance: "; std::cin >> initialBalance;
    std::cout << "Enter Overdraft Limit: "; std::cin >> limit;
    bank.createCheckingAccount(clientId, initialBalance, limit);
}

void handleCreateSavings(Bank& bank) {
    int clientId; double initialBalance, rate;
    std::cout << "Enter Client ID: "; std::cin >> clientId;
    std::cout << "Enter Initial Balance: "; std::cin >> initialBalance;
    std::cout << "Enter Interest Rate (%): "; std::cin >> rate;
    bank.createSavingsAccount(clientId, initialBalance, rate);
}

void handleDeposit(Bank& bank) {
    std::string accountNumber; double amount;
    std::cout << "Enter Account Number: "; std::cin >> accountNumber;
    std::cout << "Enter Amount to Deposit: "; std::cin >> amount;
    bank.depositToAccount(accountNumber, amount);
}

void handleWithdraw(Bank& bank) {
    std::string accountNumber; double amount;
    std::cout << "Enter Account Number: "; std::cin >> accountNumber;
    std::cout << "Enter Amount to Withdraw: "; std::cin >> amount;
    bank.withdrawFromAccount(accountNumber, amount);
}

void handleTransfer(Bank& bank) {
    std::string fromAccount, toAccount; double amount;
    std::cout << "Enter Sender Account Number: "; std::cin >> fromAccount;
    std::cout << "Enter Receiver Account Number: "; std::cin >> toAccount;
    std::cout << "Enter Amount to Transfer: "; std::cin >> amount;
    bank.transfer(fromAccount, toAccount, amount);
}

void handleRequestLoan(Bank& bank) {
    int clientId; double principal, rate;
    std::cout << "Enter Client ID: "; std::cin >> clientId;
    std::cout << "Enter Principal Amount: "; std::cin >> principal;
    std::cout << "Enter Interest Rate (%): "; std::cin >> rate;
    bank.requestLoan(clientId, principal, rate);
}

void handlePayLoan(Bank& bank) {
    int loanId; double amount;
    std::cout << "Enter Loan ID: "; std::cin >> loanId;
    std::cout << "Enter Payment Amount: "; std::cin >> amount;
    bank.payLoan(loanId, amount);
}

void adminFlow(Bank& bank) {
    int id;
    std::string password;
    std::cout << "Enter Admin ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    Admin* admin = bank.authenticateAdmin(id, password);
    if (!admin) {
        std::cout << "Invalid Admin ID or Password.\n";
        return;
    }

    int choice = -1;
    while (choice != 0) {
        displayAdminMenu(admin);
        if (!(std::cin >> choice)) {
            std::cin.clear(); std::cin.ignore(10000, '\n'); choice = -1;
        }

        switch (choice) {
            case 1: handleCreateClient(bank); break;
            case 2: bank.displayAllClients(); break;
            case 3: handleCreateChecking(bank); break;
            case 4: handleCreateSavings(bank); break;
            case 5: bank.displayAllAccounts(); break;
            case 6: bank.displayTransactions(); break;
            case 7: bank.displayAllLoans(); break;
            case 0: std::cout << "Logging out...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

void clientFlow(Bank& bank) {
    int choice = -1;
    while (choice != 0) {
        displayClientMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear(); std::cin.ignore(10000, '\n'); choice = -1;
        }
        
        switch (choice) {
            case 1: handleDeposit(bank); break;
            case 2: handleWithdraw(bank); break;
            case 3: handleTransfer(bank); break;
            case 4: handleRequestLoan(bank); break;
            case 5: handlePayLoan(bank); break;
            case 0: std::cout << "Returning to main menu...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

int main() {
    Bank myBank;
    std::cout << "Initializing Banking System...\n";
    myBank.loadData();
    
    int choice = -1;
    while (choice != 0) {
        displayMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = -1;
        }
        
        switch (choice) {
            case 1: adminFlow(myBank); break;
            case 2: clientFlow(myBank); break;
            case 0: 
                myBank.saveData();
                std::cout << "Exiting system. Goodbye!\n"; 
                break;
            default: std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
