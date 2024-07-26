#include "Page.h"

Page::Page(QWidget* parent)
    : QWidget(parent)
{
    //applyStyleSheet(":/styles/page.qss");
}

Page::~Page()
{
}

void Page::goBack()
{
    emit GoBackRequested(this);
}