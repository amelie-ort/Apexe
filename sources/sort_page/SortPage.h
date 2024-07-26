#ifndef SORTPAGE_H
#define SORTPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QPointer>
#include <QTimer>

#include "../page/Page.h"

#include "../../util/style/applyStyleSheet.h"
#include "../../util/parserFile/ParserFile.h"
#include "../../util/widgets/Widgets.h"

#include "sources/sort/Sort.h" 

#include "ui_SortPage.h"

namespace Ui {
    class SortPage;
}

class SortPage : public Page
{
    Q_OBJECT

public:
    explicit SortPage(QWidget* parent = nullptr);
    ~SortPage();


private:
    QList<QJsonObject> algorithms;
    QPointer<Sort> currentSortWidget;

    Ui::SortPage* ui;
    
    void initializeUI();
    void updateUIForNewSort();
    void updateSortUI();

    void selectSort(const QJsonObject& algorithm);
    void deleteSortWidget();

    // Gestion du visuel du titre
    void updateTitleUI();

    // Gestion du visuel du scroll 
    void initializeScrollUI();
    void updateScrollUI();
    

    // Gestion du visuel des caracteristique
    void initializeCharacteristicUI();

    // Gestion du visuel de la complexité
    void initializeComplexityUI();
    void updateComplexityUI();
    QLabel* nbComparaisonLabel;
    QLabel* nbDeplacementLabel;
    QLabel* nbCopieLabel;

    // Gestion du visuel du tri
    void initializeVisuelSortUI();
    void setBarColor(int index, QBarSet& set);
    void updateVisuelSortUI();
    QChartView* visuelSortArea;

    // Gestion du bouton de lancerment du tri 
    void initializeButton();
    void updateButton();

    Sort* createSortWidget(const QJsonObject& algorithm);

    //animation 
    QTimer* animationTimer;
    void startAnimation();
    void updateAnimation();

};

#endif // SORTPAGE_H
