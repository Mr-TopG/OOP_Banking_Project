#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <string>
#include <vector>

class Client : public Person {
private:
    std::string address;
    std::string phoneNumber;
    std::vector<std::string> accountNumbers;
    std::vector<int> loanIds;

public:
    Client(int id, const std::string& firstName, const std::string& lastName, const std::string& password,
           const std::string& address, const std::string& phoneNumber);

    // Getters
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    const std::vector<std::string>& getAccountNumbers() const;
    const std::vector<int>& getLoanIds() const;

    // Setters
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);

    // Relationship Management
    void addAccount(const std::string& accountNumber);
    void addLoan(int loanId);

    // Override pure virtual function
    void displayInfo() const override;
    void displayRelationships() const;
};

#endif // CLIENT_H
