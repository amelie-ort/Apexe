#include "WelcomePage.h"
#include <QResizeEvent>


WelcomePage::WelcomePage(QWidget* parent)
    : Page(parent)
    , ui(new Ui::WelcomePage)
{
    ui->setupUi(this);

    ui->label->setObjectName("title");

    connect(ui->GameButton, &QPushButton::clicked, this, &WelcomePage::clickOnGameButtonPage);
    connect(ui->SortButton, &QPushButton::clicked, this, &WelcomePage::clickOnSortButtonPage);
    connect(ui->BankButton, &QPushButton::clicked, this, &WelcomePage::GoOnBankPageRequested);
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::clickOnGameButtonPage()
{
    emit GoOnGamePageRequested();
}

void WelcomePage::clickOnSortButtonPage()
{
    emit GoOnSortPageRequested();
}

void WelcomePage::clickOnBankButtonPage()
{
    emit GoOnBankPageRequested();
}
