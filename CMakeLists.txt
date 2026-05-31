cmake_minimum_required(VERSION 3.10)
project(BankingSystem CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set directories
include_directories(include)

# Executable output
add_executable(BankingSystem 
    src/main.cpp
    src/Person.cpp
    src/Client.cpp
    src/Admin.cpp
    src/Bank.cpp
    src/Account.cpp
    src/CheckingAccount.cpp
    src/SavingsAccount.cpp
    src/Transaction.cpp
    src/Loan.cpp
)
