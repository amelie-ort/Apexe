#include "applyStyleSheet.h"

void applyStyleSheet(const QString& styleSheetPath, QWidget* widget)
{
    QFile file(styleSheetPath);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString newStyleSheet = stream.readAll();
        if (widget) {
            QString currentStyleSheet = widget->styleSheet();
            widget->setStyleSheet(currentStyleSheet + "\n" + newStyleSheet);
        }
        else {
            QString currentStyleSheet = qApp->styleSheet();
            qApp->setStyleSheet(currentStyleSheet + "\n" + newStyleSheet);
        }
        file.close();
    }
    else {
        qWarning() << "Could not open file:" << styleSheetPath;
    }
}