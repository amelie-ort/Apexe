#include "Bank.h"
#include <random>

Bank::Bank() : m_transactionGenerator(m_accounts, m_activeTransactions), m_running(false) {}

void Bank::start() {
    m_running = true;
    m_transactionGenerator.start();
    m_threads.emplace_back(&Bank::displayBalances, this);
}

void Bank::stop() {
    m_running = false;
    m_transactionGenerator.stop();
    for (auto& thread : m_threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    for (auto& entry : m_activeTransactions) {
        delete entry.second;
    }
    m_activeTransactions.clear();
    for (auto account : m_accounts) {
        delete account;
    }
    m_accounts.clear();
    m_threads.clear();
    std::cout << "Bank stopped." << std::endl;
}

void Bank::createAccounts(int numAccounts) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(100, 1000);

    for (int i = 0; i < numAccounts; ++i) {
        m_accounts.push_back(new BankAccount(distribution(generator), i));
    }
}

void Bank::displayBalances() {
    while (m_running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Account balances:" << std::endl;
        for (size_t i = 0; i < m_accounts.size(); ++i) {
            std::cout << "Account " << i + 1 << ": " << m_accounts[i]->getBalance() << std::endl;
        }
        std::cout << "Active Transactions:" << std::endl;
        for (const auto& transaction : m_activeTransactions) {
            std::cout << "Transaction " << transaction.first << ": " << transaction.second->getLifeCycle() << transaction.second->getAccounts() << std::endl;
        }
        std::cout << "______________" << std::endl;
    }
}

Bank::~Bank() {
    stop();
}
