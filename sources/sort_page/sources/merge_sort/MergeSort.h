#ifndef MERGESORT_H
#define MERGESORT_H

#include "../sort/Sort.h"
#include <QVector>

class MergeSort : public Sort
{
    Q_OBJECT

public:
    MergeSort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

protected:
    void sortStep() override;

private:
    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

    int currentStep;
    QVector<int> tempList;
    int listSize;
    int leftIndex;
    int rightIndex;
    int midIndex;
    int phase; // 0 = divide, 1 = merge
};

#endif // MERGESORT_H
