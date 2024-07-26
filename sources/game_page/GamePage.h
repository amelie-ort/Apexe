#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QRandomGenerator>
#include <QTimer>

#include "../page/Page.h"

#include "../../util/style/applyStyleSheet.h"
#include "../../util/widgets/widgets.h"

#include "ui_GamePage.h"
#include "sources/RockPaperScissors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GamePage; }
QT_END_NAMESPACE

class GamePage : public Page
{
    Q_OBJECT

public:
    explicit GamePage(QWidget* parent = nullptr);
    ~GamePage();

private slots:
    void updateUI(Status status);



private:

    const int iconSize;
    const int iconSizeSelected;

    QPushButton* seletedButton;

    Ui::GamePage* ui;
    RockPaperScissors* rps;

    QLabel* statusLabel;

    QPushButton* rockButton;
    QPushButton* paperButton;
    QPushButton* scissorsButton;

    QPushButton* rockComputerButton;
    QPushButton* paperComputerButton;
    QPushButton* scissorsComputerButton;

    void clickOnChoice(Choice choice, QPushButton* button);
    void selectButton(QPushButton* button);
    void unSelectButton(QPushButton* button);

    void initializeUI();

    //animation
    QList<QPushButton*> computerButtons;
    QTimer* animationTimer;
    int animationDuration;
    int elapsedTime;

    void startComputerAnimation();
    void updateComputerAnimation();
    
};

#endif // GAMEPAGE_H
