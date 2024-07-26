#include "SelectionSort.h"
#include <QDebug>

SelectionSort::SelectionSort(QWidget* parent, const QJsonObject& params)
    : Sort(parent, params)
{
    index = 0;
    comparedIndex = 0;
    minIndex = 0;
    listSize = exempleList.size(); 
}

void SelectionSort::sortStep()
{
    coloredIndex.clear();
    if (status == END) {
        return;
    }

    if (index < 0 || index >= listSize) {
        status = END;
        return;
    }

    if (comparedIndex >= listSize) {
        if (minIndex != index) {
            std::swap(exempleList[index], exempleList[minIndex]);
            incrementDeplacement();
            incrementCopie();
        }
        index++;
        comparedIndex = index;
        minIndex = index; 
    }

    if (index < listSize) {
        incrementComparaison();
        coloredIndex.push_back({ comparedIndex, minIndex });
        if (exempleList[comparedIndex] < exempleList[minIndex]) {
            minIndex = comparedIndex;
        }
        comparedIndex++;
    }

    if (index >= listSize - 1) {
        status = END;
    }
}