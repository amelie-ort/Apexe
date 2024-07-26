#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <QWidget>

enum Choice { ROCK, PAPER, SCISSORS };
enum Status { READY, END_SCREEN };

class RockPaperScissors : public QWidget {
    Q_OBJECT

public:
    explicit RockPaperScissors(QWidget* parent = nullptr);
    ~RockPaperScissors();

    void changeStatus(Status newStatus);
    void setGamerOneChoice(Choice choice);
    void setGamerTwoChoice(Choice choice);

    QString determineWinner();
    void play();

signals:
    void statusChanged(Status newStatus);

private:
    Choice gamerOne;
    Choice gamerTwo;
    Status status;

    Choice getRandomChoice() const;
    QString choiceToString(Choice choice);
};

#endif // ROCKPAPERSCISSORS_H
