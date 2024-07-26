#include "widgets.h"


template<typename WidgetType>
WidgetType* createWidget(const QString& text, QLayout* layout)
{
    WidgetType* widget = new WidgetType(text, this);
    layout->addWidget(widget);
    return widget;
}

QPushButton* createButton(const QString& text, const QString& translatedText, QLayout* layout)
{
    QPushButton* button = new QPushButton(text);
    button->setText(translatedText);
    
    layout->addWidget(button);
    return button;
}

QPushButton* createIconButton(const QString& iconPath, const int iconSize, QLayout* layout, QString className)
{
    QPushButton* button = new QPushButton();
    button->setIcon(QIcon(iconPath));
    button->setIconSize(QSize(iconSize, iconSize));
    button->setFixedSize(QSize(iconSize + 5, iconSize + 5));
    button->setObjectName(className);

    layout->addWidget(button);
    return button;
}

void createHorizontalLayoutWithTitleAndItems(QVBoxLayout* mainLayout, const QString& title,const QStringList& items) {
    QHBoxLayout* hLayout = new QHBoxLayout();

    QLabel* titleLabel = new QLabel(title + " :");
    hLayout->addWidget(titleLabel);

    for (int i = 0; i < items.size(); ++i) {
        QString item = items.at(i);
        QLabel* itemLabel = new QLabel(item);
        hLayout->addWidget(itemLabel);
    }

    mainLayout->addLayout(hLayout);
}

void createHorizontalLayoutWithTitleAndItem(QVBoxLayout* mainLayout, const QString& title, const QString& item) {
    QHBoxLayout* hLayout = new QHBoxLayout();

    QLabel* titleLabel = new QLabel(title + " :");
    hLayout->addWidget(titleLabel);

    QLabel* itemLabel = new QLabel(item);
    hLayout->addWidget(itemLabel);

    mainLayout->addLayout(hLayout);
}

void createHorizontalLayoutWithTitleAndLabel(QVBoxLayout* mainLayout, const QString& title, QLabel* label) {
    QHBoxLayout* hLayout = new QHBoxLayout();

    QLabel* titleLabel = new QLabel(title + " :");
    hLayout->addWidget(titleLabel);

    hLayout->addWidget(label);

    mainLayout->addLayout(hLayout);
}

void clearLayout(QLayout* layout) {
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        }
        else if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout);
            delete childLayout;
        }
    }
}