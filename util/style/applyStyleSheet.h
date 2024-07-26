#ifndef APPLY_STYLESHEET_H
#define APPLY_STYLESHEET_H

#include <QString>
#include <QWidget>
#include <QApplication>
#include <QFile>
#include <QTextStream>

void applyStyleSheet(const QString& styleSheetPath, QWidget* widget = nullptr);

#endif // APPLY_STYLESHEET_H
