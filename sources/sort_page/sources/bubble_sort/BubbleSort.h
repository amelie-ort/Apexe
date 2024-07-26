#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "../sort/Sort.h"

class BubbleSort : public Sort
{
    Q_OBJECT

public:
    BubbleSort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

protected:
    void sortStep() override;

private:
    int index;
    int listSize;
    bool swapped;
};

#endif // BUBBLESORT_H
