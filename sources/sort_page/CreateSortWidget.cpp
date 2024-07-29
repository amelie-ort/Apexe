#include "SortPage.h"

#include <QDebug>

#include "sources/insertion_sort/InsertionSort.h" 
#include "sources/selection_sort/SelectionSort.h"
#include "sources/bubble_sort/BubbleSort.h"
#include "sources/quick_sort/QuickSort.h"

Sort* SortPage::createSortWidget(const QJsonObject& algorithm)
{
    Sort* sortWidget = nullptr;
    if (algorithm["name"].toString() == "Insertion Sort") {
        sortWidget = new InsertionSort(this, algorithm);
    }
    else if (algorithm["name"].toString() == "Selection Sort") {
        sortWidget = new SelectionSort(this, algorithm);
    }
    else if (algorithm["name"].toString() == "Bubble Sort") {
        sortWidget = new BubbleSort(this, algorithm);
    }
    else if (algorithm["name"].toString() == "Quick Sort") {
        sortWidget = new QuickSort(this, algorithm);
    }
    else {
        qDebug() << "The chosen sorting algorithm does not exist";
    }
    return sortWidget;
}