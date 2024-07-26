#ifndef SORT_H
#define SORT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QRandomGenerator>
#include <QHBoxLayout>
#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

#include "../../../util/parserFile/ParserFile.h"

enum SortStatus { IN_PROGRESS, END };

class Sort : public QWidget
{
    Q_OBJECT

public:
    Sort(QWidget* parent = nullptr, const QJsonObject& params = QJsonObject());

    const QString& getName() const { return name; }

    const QStringList& getAvantages() const { return avantages; }
    const QStringList& getDisadvantages() const { return disadvantages; }
    const QStringList& getUses() const { return uses; }
    const QStringList& getOther() const { return other; }

    const QString& getBestComplexity() const { return bestComplexity; }
    const QString& getWorstComplexity() const { return worstComplexity; }
    const QString& getAverageComplexity() const { return averageComplexity; }
    const QString& getStorageComplexity() const { return storageComplexity; }

    int getNbComparaison() const { return nbComparaison; }
    int getNbDeplacement() const { return nbDeplacement; }
    int getNbCopie() const { return nbCopie; }

    SortStatus getStatus() const { return status; }

    const QVector<int> getExempleList() const { return exempleList; }
    const QVector<QVector<int>> getColoredIndex() const { return coloredIndex; }

    virtual void sortStep() = 0;

protected:
    QVector<int> exempleList;

    QString name;

    QStringList avantages;
    QStringList disadvantages;
    QStringList uses;
    QStringList other;

    QString bestComplexity;
    QString worstComplexity;
    QString averageComplexity;
    QString storageComplexity;

    int nbComparaison;
    int nbDeplacement;
    int nbCopie;

    SortStatus status;

    void parseJson(const QJsonObject& params);
    void generateExempleList();

    void incrementComparaison();
    void incrementDeplacement();
    void incrementCopie();

    void resetCounters();

    QVector<QVector<int>> coloredIndex;
};

#endif // SORT_H
