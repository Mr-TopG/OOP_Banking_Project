#include <iostream>

#include "Bank.h"

void displayMenu() {
    std::cout << "\n=== Banking System ===\n";
    std::cout << "1. Admin: Create Client\n";
    std::cout << "2. Admin: View All Clients\n";
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
            case 0:
                std::cout << "Exiting system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
