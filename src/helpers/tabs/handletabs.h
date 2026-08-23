#pragma once

#include <QString>
#include <QTabWidget>

class HandleTabs
{
public:
    HandleTabs(QTabWidget* mainUi);

    void addNewTab();
    void removeTab(const int& index);

private:
    QTabWidget* m_tabWidget;
    int m_tabCounter = 2;
};
