#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpers/tabs/handletabs.h"

#include <QWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabsClosable(true);

    handleTabs = std::make_unique<HandleTabs>(ui->tabWidget);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::onTabCloseRequested);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//==========================================================
//                          Tabs
//==========================================================

void MainWindow::on_actionNew_Tab_triggered() {
    handleTabs->addNewTab();
}

void MainWindow::onTabCloseRequested(int index) {
    handleTabs->removeTab(index);
}

