#include "GamePage.h"

GamePage::GamePage(QWidget* parent)
    : Page(parent)
    , ui(new Ui::GamePage)
    , rps(new RockPaperScissors(this)) 
    , iconSize(150)
    , iconSizeSelected(250)
    , animationTimer(new QTimer(this))
    , elapsedTime(0)
{
    applyStyleSheet(":/styles/gamePage.qss");
    
    ui->setupUi(this);
    initializeUI();

    connect(ui->BackToWelcomePage, &QPushButton::clicked, this, &GamePage::goBack);
    connect(rps, &RockPaperScissors::statusChanged, this, &GamePage::updateUI);
    connect(animationTimer, &QTimer::timeout, this, &GamePage::updateComputerAnimation); 

    seletedButton = nullptr;
}


GamePage::~GamePage()
{
    delete ui;
    delete rps;
}

void GamePage::initializeUI()
{
    statusLabel = new QLabel("Choose Rock, Paper, or Scissors:!");
    ui->infoArea->addWidget(statusLabel);
    ui->infoArea->setAlignment(Qt::AlignCenter);
    statusLabel->setObjectName("title");

    rockButton = createIconButton(":/images/rockGamer.png", this->iconSize, ui->gamerArea, "gamerCard");
    paperButton = createIconButton(":/images/paperGamer.png", this->iconSize, ui->gamerArea, "gamerCard");
    scissorsButton = createIconButton(":/images/scissorsGamer.png", this->iconSize, ui->gamerArea, "gamerCard");

    connect(rockButton, &QPushButton::clicked, [this]() { clickOnChoice(ROCK, rockButton); });
    connect(paperButton, &QPushButton::clicked, [this]() { clickOnChoice(PAPER, paperButton); });
    connect(scissorsButton, &QPushButton::clicked, [this]() { clickOnChoice(SCISSORS, scissorsButton); });

    rockComputerButton = createIconButton(":/images/rockComputer.png", this->iconSize, ui->computerArea, "card");
    paperComputerButton = createIconButton(":/images/paperComputer.png", this->iconSize, ui->computerArea, "card");
    scissorsComputerButton = createIconButton(":/images/scissorsComputer.png", this->iconSize, ui->computerArea, "card");

    computerButtons = { rockComputerButton, paperComputerButton, scissorsComputerButton };
    updateUI(READY); 
}

void GamePage::updateUI(Status status)
{
    switch (status) {
    case READY:
        statusLabel->setText("Choose Rock, Paper, or Scissors:");
        break;
    case END_SCREEN:

        break;
    }
}

void GamePage::clickOnChoice(Choice choice, QPushButton* button)
{
    if (seletedButton) { unSelectButton(seletedButton); };
    rps->setGamerOneChoice(choice);
    selectButton(button);
    startComputerAnimation();
    rps->play();
    seletedButton = button;
}


void GamePage::selectButton(QPushButton* button)
{
    button->setIconSize(QSize(this->iconSizeSelected, this->iconSizeSelected));
    button->setFixedSize(QSize(this->iconSizeSelected + 5, this->iconSizeSelected + 5));
}

void GamePage::unSelectButton(QPushButton* button)
{
    button->setIconSize(QSize(this->iconSize, this->iconSize));
    button->setFixedSize(QSize(this->iconSize + 5, this->iconSize + 5));
}

void GamePage::startComputerAnimation()
{
    animationDuration = QRandomGenerator::global()->bounded(1000, 3000);
    elapsedTime = 0;
    animationTimer->start(100);
}

void GamePage::updateComputerAnimation()
{
    elapsedTime += 100;
    static int currentIndex = 0;

    if (elapsedTime >= animationDuration) {
        animationTimer->stop();
        QPushButton* finalButton = computerButtons[currentIndex];
        rps->setGamerTwoChoice(static_cast<Choice>(currentIndex));
        selectButton(finalButton);
        statusLabel->setText(rps->determineWinner());
        return;
    }

    unSelectButton(computerButtons[currentIndex]);
    currentIndex = (currentIndex + 1) % computerButtons.size();
    selectButton(computerButtons[currentIndex]);
}