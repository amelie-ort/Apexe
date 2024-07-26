#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <thread>
#include <functional>
#include "../bank_account/BankAccount.h"

enum LifeCycle { WAINTING_WITHDRAWAL, WITHDRAWAL, WAINTING_DEPOSIT, DEPOSIT, TRANSACTION_END };

class Transaction {
public:
    Transaction(BankAccount& issuingAccount, BankAccount& receivingAccount, double amount, int identifier);
    ~Transaction();

    void execute();

    void start();

    LifeCycle getLifeCycle() const;
    int getIdentifier() const;
    std::string getAccounts() const;



private:
    int m_identifier;
    BankAccount& m_issuingAccount;
    BankAccount& m_receivingAccount;
    double m_amount;
    LifeCycle m_life_cycle;
    std::thread m_thread;
};

#endif // TRANSACTION_H
