#include "BubbleSort.h"
#include <QDebug>

BubbleSort::BubbleSort(QWidget* parent, const QJsonObject& params)
    : Sort(parent, params), index(0), swapped(true)
{
    listSize = exempleList.size();
}

void BubbleSort::sortStep()
{
    coloredIndex.clear();

    if (status == END) {
        return;
    }

    if (listSize <= 1) {
        status = END;
        return;
    }

    if (!swapped) {
        status = END;
        return;
    }

    swapped = false;

    for (int j = 0; j < listSize - index - 1; j++) {
        incrementComparaison();
        coloredIndex.push_back({ j, j + 1 });

        if (exempleList[j] > exempleList[j + 1]) {
            std::swap(exempleList[j], exempleList[j + 1]);
            swapped = true;
            incrementDeplacement();
            incrementCopie();
        }
    }

    index++;

    if (!swapped || index >= listSize) {
        status = END;
    }

}
