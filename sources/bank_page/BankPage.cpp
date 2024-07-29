#include "BankPage.h"

BankPage::BankPage(QWidget* parent)
    : Page(parent),
    ui(new Ui::BankPage), 
    bank(new Bank)
{
    applyStyleSheet(":/styles/bankPage.qss");
    ui->setupUi(this);
    ui->mainLayout->setStretch(0, 1); // area -> top
    ui->mainLayout->setStretch(1, 2); // area -> unprocessTransaction
    ui->mainLayout->setStretch(2, 6); // area -> activeTransaction
    ui->mainLayout->setStretch(3, 2); // area -> transactionProcessed
    
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

    std::vector<QColor> colors = { QColor("#A7C7E7"), QColor("#F8C3CD"), QColor("#C5A3FF"), QColor("#B9E4C9"),
                                   QColor("#F9D4A5"), QColor("#FFF9A5") };

    int colorIndex = 0;
    
    std::unordered_map<int, QVBoxLayout*> accountLayouts;
    for (const auto& account : accounts) {
        int accountId = account->getIdentifier();
        QVBoxLayout* accountLayout = new QVBoxLayout();
        accountLayouts[accountId] = accountLayout;

        QLabel* accountLabel = createBankAccountTitle(account);
        accountLabel->setObjectName("bankAccountTitle");
        accountLayout->addWidget(accountLabel);
        accountLayout->addStretch();  

        ui->activeTransaction->addLayout(accountLayout);
    }

    for (const auto& pair : transactions) {
        Transaction* transaction = pair.second;
        QWidget* transactionWidget = createTransactionWidget(transaction, accountLayouts);
        
        transactionWidget->setObjectName("transaction");
        transactionWidget->setStyleSheet(QString("background-color: %1").arg(colors[colorIndex % colors.size()].name()));
        colorIndex++;
        
        switch (transaction->getLifeCycle()) {
            case WAINTING_WITHDRAWAL:
                ui->unprocessTransaction->addWidget(transactionWidget);
                break;
            case WITHDRAWAL:
                accountLayouts[transaction->getIssuingAccountIdentifier()]->addWidget(transactionWidget);
                break;
            case WAINTING_DEPOSIT:
                ui->unprocessTransaction->addWidget(transactionWidget);
                break;
            case DEPOSIT:
                accountLayouts[transaction->getReceivingAccountIdentifier()]->addWidget(transactionWidget);
                break;
            case TRANSACTION_END:
                ui->transactionProcessed->addWidget(transactionWidget);
                break;
        }
    }
}

void BankPage::updateUI(){
    clearLayout(ui->unprocessTransaction);
    clearLayout(ui->activeTransaction);
    clearLayout(ui->transactionProcessed);

    initializeUI();
}

QLabel* BankPage::createBankAccountTitle(BankAccount* account) {
    return new QLabel(QString("Compte n%1 Solde: %2")
                      .arg(account->getIdentifier())
                      .arg(QString::number(account->getBalance())));
}

QWidget* BankPage::createTransactionWidget(Transaction* transaction, std::unordered_map<int, QVBoxLayout*>& accountLayouts) {
    QWidget* transactionWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(transactionWidget);

    QLabel* transactionLabel = new QLabel(QString("Transaction %1: %2 -> %3, Montant: %4")
                                          .arg(QString::number(transaction->getIdentifier()))
                                          .arg(QString::number(transaction->getIssuingAccountIdentifier()))
                                          .arg(QString::number(transaction->getReceivingAccountIdentifier()))
                                          .arg(QString::number(transaction->getAmount())));
    layout->addWidget(transactionLabel);

    QCheckBox* withdrawalCheckBox = new QCheckBox("Retrait");
    QCheckBox* depositCheckBox = new QCheckBox("Dépôt");

    switch (transaction->getLifeCycle()) {
        case WAINTING_WITHDRAWAL:
            break;
        case WITHDRAWAL:
            break;
        case WAINTING_DEPOSIT:
            withdrawalCheckBox->setChecked(true);
            break;
        case DEPOSIT:
            withdrawalCheckBox->setChecked(true);
            break;
        case TRANSACTION_END:
            withdrawalCheckBox->setChecked(true);
            depositCheckBox->setChecked(true);
            break;
    }

    layout->addWidget(withdrawalCheckBox);
    layout->addWidget(depositCheckBox);

    return transactionWidget;
}
