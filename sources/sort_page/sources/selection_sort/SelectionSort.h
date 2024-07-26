#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "../sort/Sort.h"

class SelectionSort : public Sort
{
    Q_OBJECT

public:
    SelectionSort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

protected:
    void sortStep() override;

    int index;    
    int comparedIndex;
    int minIndex; 

    int listSize;
};

#endif // SELECTIONSORT_H