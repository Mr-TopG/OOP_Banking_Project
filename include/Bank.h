#ifndef BANK_H
#define BANK_H

#include "Client.h"
#include <vector>

class Bank {
private:
    std::vector<Client> clients;
    int nextClientId = 1;

public:
    Bank() = default;

    // Client Management
    void createClient(const std::string& firstName, const std::string& lastName, 
                      const std::string& password, const std::string& address, 
                      const std::string& phoneNumber);
    
    Client* getClient(int id);
    void displayAllClients() const;
};

#endif // BANK_H
