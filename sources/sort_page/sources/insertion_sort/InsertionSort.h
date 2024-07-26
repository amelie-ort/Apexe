#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "../sort/Sort.h"

class InsertionSort : public Sort
{
    Q_OBJECT

public:
    InsertionSort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

protected:
    void sortStep() override;

private:
    int index;
    int current;
    int listSize;
    int comparedIndex;
};

#endif // INSERTIONSORT_H
