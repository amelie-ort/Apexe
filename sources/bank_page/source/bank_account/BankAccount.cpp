#include "BankAccount.h"

BankAccount::BankAccount(double balance, int identifier) : m_balance(balance), m_identifier(identifier){}

BankAccount::~BankAccount() {}

void BankAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_balance += amount;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void BankAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_balance -= amount;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

double BankAccount::getBalance() const {
    //std::lock_guard<std::mutex> lock(m_mutex);
    return m_balance;
}

int BankAccount::getIdentifier() {
    return m_identifier;
}