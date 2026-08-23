#include "handletabs.h"

#include <QVBoxLayout>
#include <QPlainTextEdit>

HandleTabs::HandleTabs(QTabWidget* tabWidget) : m_tabWidget(tabWidget) {
}

void HandleTabs::addNewTab() {
    ++m_tabCounter;
    QString nameNewTab = QString("Tab %1").arg(m_tabCounter);

    QWidget *newTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(newTab);

    layout->addWidget(new QPlainTextEdit(newTab));

    m_tabWidget->addTab(newTab, nameNewTab);
    m_tabWidget->setCurrentWidget(newTab);
}

void HandleTabs::removeTab(const int& index) {
    QWidget* tabWidget = m_tabWidget->widget(index);
    m_tabWidget->removeTab(index);

    tabWidget->deleteLater();
}