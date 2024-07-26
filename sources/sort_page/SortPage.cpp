#include "SortPage.h"

SortPage::SortPage(QWidget* parent)
    : Page(parent),
    ui(new Ui::SortPage),
    currentSortWidget(nullptr), 
    animationTimer(new QTimer(this))
{
    applyStyleSheet(":/styles/sortPage.qss");
    ui->setupUi(this);

    algorithms = JsonFileToList(":/resources/algorithms.json");
    initializeUI();

    connect(animationTimer, &QTimer::timeout, this, &SortPage::updateAnimation);
    connect(ui->BackToWelcomePage, &QPushButton::clicked, this, &SortPage::goBack);
}

SortPage::~SortPage()
{
    delete ui;
}


void SortPage::initializeUI() {
    initializeScrollUI();
}

void SortPage::updateUIForNewSort() {
    initializeCharacteristicUI();
    initializeComplexityUI();
    initializeVisuelSortUI();
    initializeButton();

    updateScrollUI();
    updateTitleUI();
}

void SortPage::updateSortUI() {
    updateComplexityUI();
    updateVisuelSortUI();
    updateButton();
}

void SortPage::selectSort(const QJsonObject& algorithm)
{
    deleteSortWidget();
    currentSortWidget = createSortWidget(algorithm);
    updateUIForNewSort();
}

void SortPage::deleteSortWidget()
{
    if (currentSortWidget) {
        clearLayout(ui->complexityArea);
        clearLayout(ui->characteristicArea);
        clearLayout(ui->visuelSortArea);

        delete currentSortWidget;
    }
}

void SortPage::updateTitleUI()
{
    ui->titleSortName->setText(currentSortWidget->getName());
}

void SortPage::initializeScrollUI(){

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QWidget* scrollWidget = new QWidget(); 
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollWidget);

    for (const QJsonObject& algorithm : algorithms) {
        QPushButton* button = new QPushButton(algorithm["name"].toString());
        scrollLayout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [=]() { selectSort(algorithm); });
    }
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    ui->choiceOfSortingArea->addWidget(scrollArea);

}

void SortPage::updateScrollUI() {
    //TODO : Rendre l'�l�ment s�lectionn� plus opaque pour mieux le voir.
}

void SortPage::initializeCharacteristicUI() {
    QVBoxLayout* characteristicSortArea = new QVBoxLayout();
    createHorizontalLayoutWithTitleAndItems(characteristicSortArea, "Avantages", currentSortWidget->getAvantages());
    createHorizontalLayoutWithTitleAndItems(characteristicSortArea, "Inconvenients", currentSortWidget->getDisadvantages());
    createHorizontalLayoutWithTitleAndItems(characteristicSortArea, "Utilites", currentSortWidget->getUses());
    createHorizontalLayoutWithTitleAndItems(characteristicSortArea, "Autres", currentSortWidget->getOther());
    ui->characteristicArea->addLayout(characteristicSortArea);
}


void SortPage::initializeComplexityUI() {
    QHBoxLayout* complexitySortArea = new QHBoxLayout();

    QVBoxLayout* complexityTheoreticalArea = new QVBoxLayout();
    QLabel* titre = new QLabel("Complexite th�orique");
    complexityTheoreticalArea->addWidget(titre);
    createHorizontalLayoutWithTitleAndItem(complexityTheoreticalArea, "Meilleure complexite", currentSortWidget->getBestComplexity());
    createHorizontalLayoutWithTitleAndItem(complexityTheoreticalArea, "Pire complexite", currentSortWidget->getWorstComplexity());
    createHorizontalLayoutWithTitleAndItem(complexityTheoreticalArea, "Complexite moyenne", currentSortWidget->getAverageComplexity());
    createHorizontalLayoutWithTitleAndItem(complexityTheoreticalArea, "Complexite de stockage", currentSortWidget->getStorageComplexity());
    complexitySortArea->addLayout(complexityTheoreticalArea);

    QVBoxLayout* complexityRealArea = new QVBoxLayout();
    QLabel* titre2 = new QLabel("Complexite reel");
    complexityRealArea->addWidget(titre2);
    nbComparaisonLabel = new QLabel(QString::number(currentSortWidget->getNbComparaison()));
    createHorizontalLayoutWithTitleAndLabel(complexityRealArea, "Nombre de comparaison", nbComparaisonLabel);

    nbDeplacementLabel = new QLabel(QString::number(currentSortWidget->getNbDeplacement()));
    createHorizontalLayoutWithTitleAndLabel(complexityRealArea, "Nombre de deplacement", nbDeplacementLabel);

    nbCopieLabel = new QLabel(QString::number(currentSortWidget->getNbCopie()));
    createHorizontalLayoutWithTitleAndLabel(complexityRealArea, "Nombre de copie", nbCopieLabel);

    complexitySortArea->addLayout(complexityRealArea);
    ui->complexityArea->addLayout(complexitySortArea);
}

void SortPage::updateComplexityUI() {
    nbComparaisonLabel->setText(QString::number(currentSortWidget->getNbComparaison()));
    nbDeplacementLabel->setText(QString::number(currentSortWidget->getNbDeplacement()));
    nbCopieLabel->setText(QString::number(currentSortWidget->getNbCopie()));
}


void SortPage::initializeVisuelSortUI() {
    QChart* chart = new QChart();
    QBarSeries* series = new QBarSeries();

    for (const int number : currentSortWidget->getExempleList()) {
        QBarSet* set = new QBarSet(QString::number(number));
        *set << number;
        set->setBrush(QColor(Qt::blue));
        series->append(set);
    }

    chart->addSeries(series);
    chart->legend()->setVisible(false);

    visuelSortArea = new QChartView(chart);
    visuelSortArea->setRenderHint(QPainter::Antialiasing);
    ui->visuelSortArea->addWidget(visuelSortArea);
}

void SortPage::updateVisuelSortUI() {
    QBarSeries* series = new QBarSeries();

    const QVector<int>& exampleList = currentSortWidget->getExempleList();
    for (int index = 0; index < exampleList.size(); ++index) {
        int number = exampleList[index];
        QBarSet* set = new QBarSet(QString::number(number));
        *set << number;
        set->setBrush(QBrush(Qt::blue));
        setBarColor(index, *set);
        series->append(set);
    }

    QChart* chart = visuelSortArea->chart();
    chart->removeAllSeries();
    chart->addSeries(series);
}

void SortPage::setBarColor(int index, QBarSet& set) {
    QVector<QColor> colors = { 
        Qt::red,
        Qt::magenta,
        Qt::green,
        Qt::yellow,
        Qt::black,
        Qt::cyan,
        Qt::gray,
    };
    const QVector<QVector<int>> coloredIndex = currentSortWidget->getColoredIndex();
    for (size_t i = 0; i < coloredIndex.size(); ++i) {
        QColor color = colors[i % colors.size()];
        if (coloredIndex[i].contains(index)) {
            set.setBrush(QBrush(color));
        }
        
    }
}

void SortPage::initializeButton() {
    QPushButton* button = new QPushButton("play");
    ui->complexityArea->addWidget(button);
    connect(button, &QPushButton::clicked, this, [this]() { startAnimation(); });
}

void SortPage::updateButton() {
    //TODO: mettre a rejouer pour refaire le tri et grisser lors de l'annnimation 
}

void SortPage::startAnimation() {
    animationTimer->start(100);
}

void SortPage::updateAnimation()
{
    if (currentSortWidget->getStatus() == END) {
        animationTimer->stop();
        return;
    }

    currentSortWidget->sortStep();
    updateSortUI();
}