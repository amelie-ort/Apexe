#include "QuickSort.h"
#include <QDebug>

QuickSort::QuickSort(QWidget* parent, const QJsonObject& params)
    : Sort(parent, params), leftIndex(0), rightIndex(0), pivotIndex(0)
{
    listSize = exempleList.size();
    stack.push_back(0);
    stack.push_back(listSize - 1);
}

void QuickSort::sortStep()
{
    coloredIndex.clear();

    if (status == END) {
        return;
    }

    if (stack.empty()) {
        status = END;
        return;
    }

    rightIndex = stack.back();
    stack.pop_back();
    leftIndex = stack.back();
    stack.pop_back();

    if (leftIndex < rightIndex) {
        int pivot = partition(leftIndex, rightIndex);

        if (pivot - 1 > leftIndex) {
            stack.push_back(leftIndex);
            stack.push_back(pivot - 1);
        }

        if (pivot + 1 < rightIndex) {
            stack.push_back(pivot + 1);
            stack.push_back(rightIndex);
        }
    }

}

int QuickSort::partition(int left, int right)
{
    int pivot = exempleList[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        incrementComparaison();
        coloredIndex.push_back({ j, j + 1 });

        if (exempleList[j] <= pivot) {
            i++;
            std::swap(exempleList[i], exempleList[j]);
            incrementDeplacement();
            incrementCopie();
        }
    }

    std::swap(exempleList[i + 1], exempleList[right]);
    incrementDeplacement();
    incrementCopie();

    return i + 1;
}
  