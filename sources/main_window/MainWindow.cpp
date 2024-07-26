#include "MainWindow.h"
#include <QDebug>
#include <QScopedPointer>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_welcomePage(nullptr)
    , m_gamePage(nullptr)
    , m_sortPage(nullptr)
    , m_bankPage(nullptr)
{
    applyStyleSheet(":/styles/mainWindow.qss");

    setWindowTitle("Apexe");
    setWindowOpacity(1);
    resize(1000, 800);

    SetWelcomePage(nullptr);
}

MainWindow::~MainWindow() {};

void MainWindow::SetWelcomePage(Page* oldPage) {
    TransitionToPage(m_welcomePage = new WelcomePage(this), oldPage, [this]() {
        connect(m_welcomePage, &WelcomePage::GoOnGamePageRequested, this, &MainWindow::SetGamePage);
        connect(m_welcomePage, &WelcomePage::GoOnSortPageRequested, this, &MainWindow::SetSortPage);
        connect(m_welcomePage, &WelcomePage::GoOnBankPageRequested, this, &MainWindow::SetBankPage);
        });
}

void MainWindow::SetGamePage() {
    TransitionToPage(m_gamePage = new GamePage(this), m_welcomePage, [this]() {
        connect(m_gamePage, &GamePage::GoBackRequested, this, &MainWindow::SetWelcomePage);
        });
}

void MainWindow::SetSortPage() {
    TransitionToPage(m_sortPage = new SortPage(this), m_welcomePage, [this]() {
        connect(m_sortPage, &SortPage::GoBackRequested, this, &MainWindow::SetWelcomePage);
        });
}

void MainWindow::SetBankPage() {
    TransitionToPage(m_bankPage = new BankPage(this), m_welcomePage, [this]() {
        connect(m_bankPage, &BankPage::GoBackRequested, this, &MainWindow::SetWelcomePage);
        });
}

void MainWindow::TransitionToPage(QWidget* newPage, Page* oldPage, const std::function<void()>& setupConnections) {
    if (oldPage) {
        oldPage->close();
        delete oldPage;  
    }
    setCentralWidget(newPage);
    setupConnections();
}