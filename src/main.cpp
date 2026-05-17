#include <iostream>

void displayMenu() {
    std::cout << "\n=== Banking System ===\n";
    std::cout << "1. Admin Login\n";
    std::cout << "2. Client Login\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
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
                std::cout << "Admin menu under construction.\n";
                break;
            case 2:
                std::cout << "Client menu under construction.\n";
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
