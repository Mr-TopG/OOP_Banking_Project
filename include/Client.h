#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <string>

class Client : public Person {
private:
    std::string address;
    std::string phoneNumber;

public:
    Client(int id, const std::string& firstName, const std::string& lastName, const std::string& password,
           const std::string& address, const std::string& phoneNumber);

    // Getters
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    // Setters
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);

    // Override pure virtual function
    void displayInfo() const override;
};

#endif // CLIENT_H
