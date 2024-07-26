#include "Sort.h"

Sort::Sort(QWidget* parent, const QJsonObject& params)
    : QWidget(parent), 
    exempleList(20), 
    nbComparaison(0), 
    nbDeplacement(0), 
    nbCopie(0), 
    status(IN_PROGRESS)
{
    parseJson(params);
    generateExempleList();
}

void Sort::parseJson(const QJsonObject& params)
{
    name = *extractJsonString(params, "name");

    avantages = *extractJsonArray(params, "avantages");
    disadvantages = *extractJsonArray(params, "disadvantages");
    uses = *extractJsonArray(params, "uses");
    other = *extractJsonArray(params, "other");

    QJsonObject complexity = *extractJsonObject(params, "complexity");

    bestComplexity = *extractJsonString(complexity, "best");
    worstComplexity = *extractJsonString(complexity, "worst");
    averageComplexity = *extractJsonString(complexity, "average");
    storageComplexity = *extractJsonString(complexity, "storage");
}

void Sort::generateExempleList()
{
    std::generate(exempleList.begin(), exempleList.end(),
        []() { return QRandomGenerator::global()->bounded(-20, 21); });
}


void Sort::incrementComparaison() {
    nbComparaison++;
}

void Sort::incrementDeplacement() {
    nbDeplacement++;
}

void Sort::incrementCopie() {
    nbCopie++;
}

void Sort::resetCounters() {
    nbComparaison = 0;
    nbDeplacement = 0;
    nbCopie = 0;
}
