#ifndef BANKPAGE_H
#define BANKPAGE_H

#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QCheckBox>
#include <iostream>
#include <string>

#include "../page/Page.h"

#include "ui_BankPage.h"
#include "source/bank/Bank.h"
#include "../../util/widgets/Widgets.h"


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
    void initializeUI();

private slots:
    void updateUI();
};

#endif // BANKPAGE_H
