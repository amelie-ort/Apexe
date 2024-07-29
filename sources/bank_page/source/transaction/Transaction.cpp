#include "Transaction.h"
#include <iostream>

Transaction::Transaction(BankAccount& issuingAccount, BankAccount& receivingAccount, double amount, int identifier)
    : m_issuingAccount(issuingAccount), m_receivingAccount(receivingAccount), m_amount(amount), m_identifier(identifier), m_life_cycle(WAINTING_WITHDRAWAL) {
}

Transaction::~Transaction() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    std::cout << "Transaction deleted." << std::endl;
}

void Transaction::execute() {
    m_life_cycle = WAINTING_WITHDRAWAL;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    m_life_cycle = WITHDRAWAL;
    m_issuingAccount.withdraw(m_amount);

    m_life_cycle = WAINTING_DEPOSIT;
    std::this_thread::sleep_for(std::chrono::seconds(3));


    m_life_cycle = DEPOSIT;
    m_receivingAccount.deposit(m_amount);
    
    m_life_cycle = TRANSACTION_END;
}

LifeCycle Transaction::getLifeCycle() const {
    return m_life_cycle;
}

int Transaction::getIdentifier() const {
    return m_identifier;
}

void Transaction::start() {
    m_thread = std::thread(&Transaction::execute, this);
}


int Transaction::getIssuingAccountIdentifier() const{
    return m_issuingAccount.getIdentifier();   
}

int Transaction::getReceivingAccountIdentifier() const{
    return m_receivingAccount.getIdentifier() ; 
}

double Transaction::getAmount() const {
    return m_amount;
}