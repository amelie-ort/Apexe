#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <mutex>
#include <iostream>
#include <string>


class BankAccount {
public:
    BankAccount(double balance = 0.0, int identifier = 0);
    ~BankAccount();

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance() const;
    int getIdentifier();

private:
    double m_balance;
    int m_identifier;
    mutable std::mutex m_mutex;
};

#endif // BANK_ACCOUNT_H
