#include "InsertionSort.h"
#include <QDebug>

InsertionSort::InsertionSort(QWidget* parent, const QJsonObject& params)
    : Sort(parent, params), index(1), comparedIndex(0)
{
    listSize = exempleList.size();
}

void InsertionSort::sortStep()
{
    coloredIndex.clear();

    if (status == END) {
        return;
    }

    if (index >= listSize) {
        status = END;
        return;
    }

    if (comparedIndex < 0 || exempleList[comparedIndex] <= exempleList[comparedIndex + 1]) {
        index++;
        comparedIndex = index - 1;
    }
    else {
        std::swap(exempleList[comparedIndex], exempleList[comparedIndex + 1]);
        incrementDeplacement();
        incrementCopie();
        comparedIndex--;
    }

    if (index < listSize) {
        incrementComparaison();
        coloredIndex.push_back({ comparedIndex + 1, comparedIndex + 2 });
    }

    if (index >= listSize) {
        status = END;
    }
}
