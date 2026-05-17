#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int id;
    std::string firstName;
    std::string lastName;
    std::string password;

public:
    Person(int id, const std::string& firstName, const std::string& lastName, const std::string& password);
    virtual ~Person() = default; // Virtual destructor for dynamic polymorphism

    // Getters
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPassword() const;

    // Setters
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPassword(const std::string& password);

    // Pure virtual function to make Person an abstract class
    virtual void displayInfo() const = 0;
};

#endif // PERSON_H
