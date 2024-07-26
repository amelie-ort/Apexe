#ifndef BANKPAGE_H
#define BANKPAGE_H

#include <QPushButton>

#include "../page/Page.h"

#include "ui_BankPage.h"
#include "source/bank/Bank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BankPage; }
QT_END_NAMESPACE


class BankPage : public Page
{
    Q_OBJECT

public:
    explicit BankPage(QWidget* parent = nullptr);
    ~BankPage();

private:
    Ui::BankPage* ui;

    Bank* bank;
};

#endif // BANKPAGE_H
