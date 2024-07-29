#include "MergeSort.h"
#include <QDebug>

MergeSort::MergeSort(QWidget* parent, const QJsonObject& params)
    : Sort(parent, params), currentStep(0), leftIndex(0), rightIndex(0), midIndex(0), phase(0)
{
    listSize = exempleList.size();
    tempList = exempleList;
    leftIndex = 0;
    rightIndex = listSize - 1;
}

void MergeSort::sortStep()
{
    coloredIndex.clear();

    if (status == END) {
        return;
    }

    if (listSize <= 1) {
        status = END;
        return;
    }

    if (phase == 0) {
        if (currentStep < listSize) {
            leftIndex = 0;
            rightIndex = listSize - 1;
            midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            mergeSort(leftIndex, rightIndex);
            phase = 1;
            currentStep++;
        }
    }
    else if (phase == 1) {
        merge(leftIndex, midIndex, rightIndex);
        phase = 0;
        currentStep++;
    }

    if (currentStep >= listSize) {
        status = END;
    }

}

void MergeSort::merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        incrementComparaison();
        if (tempList[i] <= tempList[j]) {
            exempleList[k] = tempList[i];
            i++;
        }
        else {
            exempleList[k] = tempList[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        exempleList[k] = tempList[i];
        i++;
        k++;
    }

    while (j <= right) {
        exempleList[k] = tempList[j];
        j++;
        k++;
    }

    for (int l = left; l <= right; l++) {
        tempList[l] = exempleList[l];
    }

    incrementDeplacement();
    incrementCopie();

    for (int l = left; l <= right; l++) {
        coloredIndex.push_back({ l });
    }
}

void MergeSort::mergeSort(int left, int right)
{
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}
