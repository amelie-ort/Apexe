#ifndef BANK_H
#define BANK_H

#include <vector>
#include <mutex>
#include <thread>
#include <iostream>
#include <unordered_map>
#include "../transaction_generator/TransactionGenerator.h"
#include "../transaction/Transaction.h"
#include "../bank_account/BankAccount.h"

class Bank {
public:
    Bank();
    ~Bank();

    void start();
    void stop();
    void createAccounts(int numAccounts);

private:
    TransactionGenerator m_transactionGenerator;
    std::vector<BankAccount*> m_accounts;
    std::vector<std::thread> m_threads;
    std::unordered_map<int, Transaction*> m_activeTransactions;
    bool m_running;

    void displayBalances();
};

#endif // BANK_H
