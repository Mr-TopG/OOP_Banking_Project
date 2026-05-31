#ifndef LOAN_H
#define LOAN_H

class Loan {
private:
    static int nextLoanId;
    int loanId;
    int clientId;
    double principal;
    double interestRate;
    double remainingBalance;

public:
    Loan(int clientId, double principal, double interestRate);
    
    // Getters
    int getLoanId() const;
    int getClientId() const;
    double getRemainingBalance() const;

    // Financial operations
    void makePayment(double amount);
    void applyInterest();
    void displayLoanInfo() const;
};

#endif // LOAN_H
