#ifndef WIDGETS_H
#define WIDGETS_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>

template<typename WidgetType>
WidgetType* createWidget(const QString& text, QLayout* layout);
QPushButton* createButton(const QString& text, const QString& translatedText, QLayout* layout);
QPushButton* createIconButton(const QString& iconPath, const int iconSize, QLayout* layout, QString className);

void createHorizontalLayoutWithTitleAndItems(QVBoxLayout* mainLayout, const QString& title,const QStringList& items);
void createHorizontalLayoutWithTitleAndItem(QVBoxLayout* mainLayout, const QString& title, const QString& item);
void createHorizontalLayoutWithTitleAndLabel(QVBoxLayout* mainLayout, const QString& title, QLabel* label);

void clearLayout(QLayout* layout);
#endif //WIDGETS_H