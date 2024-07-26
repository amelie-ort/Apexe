#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include <QPushButton>

#include "ui_WelcomePage.h"

#include "../page/Page.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomePage; }
QT_END_NAMESPACE


class WelcomePage : public Page
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget* parent = nullptr);
    ~WelcomePage();

signals:
    void GoOnGamePageRequested();
    void GoOnSortPageRequested();
    void GoOnBankPageRequested();

public slots:
    void clickOnGameButtonPage();
    void clickOnSortButtonPage();
    void clickOnBankButtonPage();

private:
    Ui::WelcomePage* ui;

};

#endif // WELCOMEPAGE_H
