#include "Bank.h"
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
