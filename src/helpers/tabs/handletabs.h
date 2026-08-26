#pragma once

#include <QString>
#include <QTabWidget>

class HandleTabs
{
public:
    HandleTabs(QTabWidget* mainUi);

    void addNewTab();
    void addNewTab(const QString& nameFile, const QString &text);

    void closeTab(const int& index);
    void closeCurrentTab();

private:
    QTabWidget* m_tabWidget;
};
