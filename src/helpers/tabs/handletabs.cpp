#include "handletabs.h"

#include <QVBoxLayout>
#include <QPlainTextEdit>

HandleTabs::HandleTabs(QTabWidget* tabWidget) : m_tabWidget(tabWidget) {
}

//==========================================================
//                          Add
//==========================================================
void HandleTabs::addNewTab() {
    QWidget *newTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(newTab);

    layout->addWidget(new QPlainTextEdit(newTab));

    m_tabWidget->addTab(newTab, "Untitled");
    m_tabWidget->setCurrentWidget(newTab);
}

void HandleTabs::addNewTab(const QString& nameFile,
                           const QString &text) {

    if (nameFile.isEmpty()) {
        // here alert
        return;
    }

    QWidget *newTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(newTab);

    QPlainTextEdit *editor = new QPlainTextEdit(text, newTab);
    layout->addWidget(editor);

    layout->setContentsMargins(0, 0, 0, 0);

    m_tabWidget->addTab(newTab, nameFile);
    m_tabWidget->setCurrentWidget(newTab);
}

//==========================================================
//                          Name and Index
//==========================================================
int HandleTabs::getIndexCurrentTab() {
    return m_tabWidget->currentIndex();
}

void HandleTabs::setNameTab(const int &index, const QString &name) {
    m_tabWidget->setTabText(index, name);
}

//==========================================================
//                          Close
//==========================================================
void HandleTabs::closeTab(const int& index) {
    if (index < 0 || index >= m_tabWidget->count()) {
        // here alert
        return;
    }

    QWidget* tabWidget = m_tabWidget->widget(index);
    m_tabWidget->removeTab(index);

    if (tabWidget)
        tabWidget->deleteLater();
}

void HandleTabs::closeCurrentTab() {
    int currentIndex = m_tabWidget->currentIndex();

    closeTab(currentIndex);
}