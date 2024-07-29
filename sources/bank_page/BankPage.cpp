#include "BankPage.h"

BankPage::BankPage(QWidget* parent)
    : Page(parent),
    ui(new Ui::BankPage), 
    bank(new Bank)
{
    applyStyleSheet(":/styles/bankPage.qss");
    ui->setupUi(this);
    connect(ui->BackToWelcomePage, &QPushButton::clicked, this, &BankPage::goBack);

    bank->createAccounts(3);
    bank->start();

    
    initializeUI();
    connect(bank, &Bank::transactionsUpdated, this, &BankPage::updateUI);
}

BankPage::~BankPage()
{
    bank->stop();
    delete ui;
    delete bank;

}


void BankPage::initializeUI() {
    auto transactions = bank->getTransactions();
    auto accounts = bank->getAccounts();
    
    std::unordered_map<int, QVBoxLayout*> accountLayouts;
    for (const auto& account : accounts) {
        int accountId = account->getIdentifier();
        QVBoxLayout* accountLayout = new QVBoxLayout();
        accountLayouts[accountId] = accountLayout;

        QLabel* accountLabel = new QLabel(QString("Account %1, Amount: %2")
                                            .arg(accountId)
                                            .arg(QString::number(account->getBalance()))
                                            );
        accountLayout->addWidget(accountLabel);

        ui->activeTransaction->addLayout(accountLayout);
    }

    for (const auto& pair : transactions) {
        Transaction* transaction = pair.second;

        QWidget* transactionWidget = new QWidget();
        QVBoxLayout* layout = new QVBoxLayout(transactionWidget);

        QLabel* transactionLabel = new QLabel(QString("Transaction %1: %2 -> %3, Amount: %4, status: %5")
                                              .arg(QString::number(transaction->getIdentifier()))
                                              .arg(QString::number(transaction->getIssuingAccountIdentifier()))
                                              .arg(QString::number(transaction->getReceivingAccountIdentifier()))
                                              .arg(QString::number(transaction->getAmount()))
                                              .arg(QString::number(transaction->getLifeCycle())));
        layout->addWidget(transactionLabel);

        QCheckBox* withdrawalCheckBox = new QCheckBox("Retrait effectué");
        QCheckBox* depositCheckBox = new QCheckBox("Dépôt effectué");


        switch (transaction->getLifeCycle()) {
            case WAINTING_WITHDRAWAL:
                ui->unprocessTransaction->addWidget(transactionWidget);
                break;
            case WITHDRAWAL:
                accountLayouts[transaction->getIssuingAccountIdentifier()]->addWidget(transactionWidget);
                break;
            case WAINTING_DEPOSIT:
                ui->unprocessTransaction->addWidget(transactionWidget);
                withdrawalCheckBox->setChecked(true);
                break;
            case DEPOSIT:
                accountLayouts[transaction->getReceivingAccountIdentifier()]->addWidget(transactionWidget);
                withdrawalCheckBox->setChecked(true);
                break;
            case TRANSACTION_END:
                ui->transactionProcessed->addWidget(transactionWidget);
                withdrawalCheckBox->setChecked(true);
                depositCheckBox->setChecked(true);
                break;
        }

        layout->addWidget(withdrawalCheckBox);
        layout->addWidget(depositCheckBox);
    }
}


void BankPage::updateUI(){
    clearLayout(ui->unprocessTransaction);
    clearLayout(ui->activeTransaction);
    clearLayout(ui->transactionProcessed);

    initializeUI();
}