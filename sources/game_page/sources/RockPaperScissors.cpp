#include "RockPaperScissors.h"
#include <cstdlib>
#include <ctime>
#include <QString>

RockPaperScissors::RockPaperScissors(QWidget* parent)
    : QWidget(parent), status(READY)
{
    gamerOne = static_cast<Choice>(-1);
    gamerTwo = static_cast<Choice>(-1);
}

RockPaperScissors::~RockPaperScissors() {
    // Qt gere la supp
}

void RockPaperScissors::changeStatus(Status newStatus) {
    emit statusChanged(newStatus); 
}

void RockPaperScissors::setGamerOneChoice(Choice choice) {
    gamerOne = choice;
    
}

void RockPaperScissors::setGamerTwoChoice(Choice choice) {
    gamerTwo = choice;
}

void RockPaperScissors::play() {
    determineWinner();
    changeStatus(END_SCREEN);
}

Choice RockPaperScissors::getRandomChoice() const {
    return static_cast<Choice>(rand() % 3);
}

QString RockPaperScissors::determineWinner() {

    QString result;
    if (gamerOne == gamerTwo) {
        result = "EGALITE ! :o";
    }
    else if ((gamerOne == ROCK && gamerTwo == SCISSORS) ||
        (gamerOne == PAPER && gamerTwo == ROCK) ||
        (gamerOne == SCISSORS && gamerTwo == PAPER)) {
        result = "GAGNE ! :D";
    }
    else {
        result = "PERDU ! :,(";
    }

    return result;
}


QString RockPaperScissors::choiceToString(Choice choice) {
    switch (choice) {
    case ROCK:
        return "Pierre";
    case PAPER:
        return "Feuille";
    case SCISSORS:
        return "Ciseaux";
    default:
        return "Inconnu";
    }
}
