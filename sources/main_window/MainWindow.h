#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../util/style/applyStyleSheet.h"

#include <QString>
#include <QObject>
#include <QMainWindow>
#include <QDebug>

#include "../page/Page.h"
#include "../welcome_page/WelcomePage.h"
#include "../game_page/GamePage.h"
#include "../sort_page/SortPage.h"
#include "../bank_page/BankPage.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() ;

public slots:

    void SetWelcomePage(Page* oldPage);

    void TransitionToPage(QWidget* newPage, Page* oldPage, const std::function<void()>& setupConnections);

    void SetGamePage();
    void SetSortPage();
    void SetBankPage();



public:
    QString m_title;

    WelcomePage* m_welcomePage;
    GamePage* m_gamePage;
    SortPage* m_sortPage;
    BankPage* m_bankPage;

};

#endif 
