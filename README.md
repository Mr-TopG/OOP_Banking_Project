# C++ OOP Banking System

A comprehensive console-based banking application built in C++ to demonstrate core Object-Oriented Programming (OOP) principles. 

## 📌 Project Overview
This project simulates a real-world banking system where administrators can manage the bank operations and clients can manage their accounts, perform transactions, and request loans. The application relies on clean architecture, separating responsibilities into modular header (`.h`) and source (`.cpp`) files.

## 🚀 Features
- **User Roles:** Separated access for `Admin` and `Client` users.
- **Account Management:** Support for different account types (Checking, Savings) using dynamic polymorphism.
- **Transactions:** Deposit, withdraw, and transfer money between accounts securely.
- **Financial Services:** Interest calculation for savings accounts and loan management.
- **Data Persistence:** Save and load system state (clients, accounts, transactions) from files.
- **Transaction History:** Keep logs of all account activities.
- **Validation:** Robust error handling for invalid operations (e.g., insufficient funds).

## 🧬 OOP Principles Applied
- **Encapsulation:** Data hiding and safe access through getters/setters.
- **Inheritance:** Class hierarchies separating common logic (e.g., `Person` -> `Client` & `Admin`).
- **Polymorphism:** Dynamic polymorphic behavior via abstract base classes (e.g., `Account` -> `CheckingAccount` & `SavingsAccount`).
- **Abstraction:** Hiding complex implementation details behind clean interfaces.

## 🏗️ Class Structure
- `Person` (Abstract base class for all users)
- `Client` (Represents bank customers)
- `Admin` (Represents bank staff)
- `Account` (Abstract base class for financial accounts)
- `CheckingAccount` & `SavingsAccount` (Concrete account types)
- `Transaction` (Logs operations)
- `Loan` (Handles borrowing money)
- `Bank` (Manages global state and orchestrates interactions)

## 🛠️ Build and Run (CMake)

### Prerequisites
- C++17 Compiler (GCC, Clang, or MSVC)
- CMake (3.10 or higher)

### Build Instructions
```bash
# Clone the repository
git clone git@github.com:Mr-TopG/OOP_Banking_Project.git
cd OOP_Banking_Project

# Create a build directory
mkdir build && cd build

# Configure and compile the project
cmake ..
make

# Run the application
./BankingSystem
```

## 📜 Development Plan
The project is structurally completed and validated through progressively isolated phases:
- **Phase 1:** Base Entities (`Person`, `Client`, logically separated logic for clients management) ✅
- **Phase 2:** Account Hierarchy (`Account`, `CheckingAccount`, `SavingsAccount`, deposits/withdrawals, accounts management, secure fund transfers) ✅
- **Phase 3:** Financial Services (`Transaction` history logs, `Loan` class) ⏳
- **Phase 4:** User roles isolation (`Admin` functionality)
- **Phase 5:** Data Persistence (File I/O logic for saving/loading)
