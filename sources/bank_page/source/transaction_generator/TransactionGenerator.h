#ifndef TRANSACTIONGENERATOR_H
#define TRANSACTIONGENERATOR_H

#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <unordered_map>
#include "../transaction/Transaction.h"
#include "../bank_account/BankAccount.h"

class TransactionGenerator {
public:
    TransactionGenerator(
        std::vector<BankAccount*>& accounts,
        std::unordered_map<int, Transaction*>& transactions);
    void start();
    void stop();

private:
    std::unordered_map<int, Transaction*>& m_activeTransactions;
    std::vector<BankAccount*>& m_accounts;
    std::thread m_thread;
    bool m_running;
    void generateTransactions();
    int m_counter;
};

#endif // TRANSACTIONGENERATOR_H
