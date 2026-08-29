#pragma once

#include <QString>
#include <QTabWidget>

class HandleTabs
{
public:
    HandleTabs(QTabWidget* tabWidget);

    int getIndexCurrentTab();

    void addNewTab();
    void addNewTab(const QString& nameFile, const QString &text);

    void setNameTab(const int &index, const QString& name);

    void closeTab(const int& index);
    void closeCurrentTab();

private:
    QTabWidget* m_tabWidget;
};
