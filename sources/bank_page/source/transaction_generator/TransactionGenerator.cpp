#include "TransactionGenerator.h"

TransactionGenerator::TransactionGenerator(std::vector<BankAccount*>& accounts, std::unordered_map<int, Transaction*>& transactions)
    : m_accounts(accounts), m_activeTransactions(transactions), m_running(false), m_counter(0) {}

void TransactionGenerator::start() {
    m_running = true;
    m_thread = std::thread(&TransactionGenerator::generateTransactions, this);
}

void TransactionGenerator::stop() {
    m_running = false;
    if (m_thread.joinable()) {
        m_thread.join();
    }
    std::cout << "TransactionGenerator stopped." << std::endl;
}

void TransactionGenerator::generateTransactions() {
    if (m_accounts.size() <= 1) {
        std::cout << "Not enough accounts to generate transactions." << std::endl;
        return;
    }

    std::default_random_engine generator;
    std::uniform_int_distribution<int> sleep_distribution(5, 15);
    std::uniform_int_distribution<int> account_distribution(0, m_accounts.size() - 1);
    std::uniform_int_distribution<int> amount_distribution(1, 100);

    while (m_running) {
        std::this_thread::sleep_for(std::chrono::seconds(sleep_distribution(generator)));

        int from = account_distribution(generator);
        int to = account_distribution(generator);

        while (from == to) {
            to = account_distribution(generator);
        }

        int amount = amount_distribution(generator);
        BankAccount* from_account = m_accounts[from];
        BankAccount* to_account = m_accounts[to];

        m_counter++;
        Transaction* transaction = new Transaction(*from_account, *to_account, amount, m_counter);
        m_activeTransactions[m_counter] = transaction;
        transaction->start();
    }
}
