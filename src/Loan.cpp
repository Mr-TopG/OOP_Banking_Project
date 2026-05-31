#include "Loan.h"
#include <iostream>

int Loan::nextLoanId = 1;

Loan::Loan(int clientId, double principal, double interestRate)
    : loanId(nextLoanId++), clientId(clientId), principal(principal), 
      interestRate(interestRate), remainingBalance(principal) {}

Loan::Loan(int loanId, int clientId, double principal, double interestRate, double remainingBalance)
    : loanId(loanId), clientId(clientId), principal(principal), interestRate(interestRate), remainingBalance(remainingBalance) {
    if (loanId >= nextLoanId) {
        nextLoanId = loanId + 1;
    }
}

int Loan::getLoanId() const { return loanId; }
int Loan::getClientId() const { return clientId; }
double Loan::getPrincipal() const { return principal; }
double Loan::getInterestRate() const { return interestRate; }
double Loan::getRemainingBalance() const { return remainingBalance; }

void Loan::makePayment(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid payment amount.\n";
        return;
    }
    if (amount > remainingBalance) {
        amount = remainingBalance; // Don't allow overpaying
    }
    remainingBalance -= amount;
    std::cout << "Payment of $" << amount << " applied to Loan ID " << loanId << ".\n";
    std::cout << "Remaining balance: $" << remainingBalance << "\n";
}

void Loan::applyInterest() {
    double interest = remainingBalance * (interestRate / 100.0);
    remainingBalance += interest;
    std::cout << "Interest of $" << interest << " applied to Loan ID " << loanId 
              << ". New balance: $" << remainingBalance << "\n";
}

void Loan::displayLoanInfo() const {
    std::cout << "Loan ID: " << loanId << " | Client ID: " << clientId 
              << " | Principal: $" << principal 
              << " | Rate: " << interestRate << "%"
              << " | Remaining: $" << remainingBalance << "\n";
}
