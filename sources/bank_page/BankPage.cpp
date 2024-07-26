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


}

BankPage::~BankPage()
{
    delete ui;
    delete bank;
}
