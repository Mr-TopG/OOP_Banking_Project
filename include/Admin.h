#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <string>

class Admin : public Person {
private:
    std::string role; // e.g., "Manager", "Teller", "System Administrator"

public:
    Admin(int id, const std::string& firstName, const std::string& lastName, const std::string& password, const std::string& role);

    // Getters and Setters
    std::string getRole() const;
    void setRole(const std::string& role);

    // Override pure virtual function
    void displayInfo() const override;
};

#endif // ADMIN_H
