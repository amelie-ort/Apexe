#ifndef PAGE_H
#define PAGE_H

#include <QWidget>

#include "../../util/style/applyStyleSheet.h"

class Page : public QWidget
{
    Q_OBJECT

public:
    explicit Page(QWidget* parent = nullptr);
    ~Page();

signals:
    void GoBackRequested(Page* oldpage);

protected slots:
    void goBack();
};

#endif // PAGE_H
