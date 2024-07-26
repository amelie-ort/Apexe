#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../sort/Sort.h"
#include <QVector>

class QuickSort : public Sort
{
    Q_OBJECT

public:
    QuickSort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

protected:
    void sortStep() override;

private:
    int partition(int left, int right);

    int leftIndex;
    int rightIndex;
    int pivotIndex;
    int listSize;
    QVector<int> stack; 
};

#endif // QUICKSORT_H
