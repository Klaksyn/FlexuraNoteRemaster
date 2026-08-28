#include <QWidget>
#include <QLabel>
#include <QProcess>
#include <QCoreApplication>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qfiledialog.h"

#include "helpers/tabs/handletabs.h"
#include "helpers/fs/fs.h"
#include "helpers/fs/fileutils.h"


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
    handleTabs->closeTab(index);
}

void MainWindow::on_actionClose_the_window_triggered() {
    handleTabs->closeCurrentTab();
}


//==========================================================
//                          New Window
//==========================================================
void MainWindow::on_actionNew_window_triggered() {
    QString programPath = QCoreApplication::applicationFilePath();

    QProcess::startDetached(programPath, QStringList());
}

//==========================================================
//                          File
//==========================================================
void MainWindow::on_actionOpen_triggered() {

    QString filePath = QFileDialog::getOpenFileName(this,
                            "open text file","","Text Files(*.txt);;All Files(*)");

    if (filePath.isEmpty())
        return;

    QString fileName = FileUtils::getFileName(filePath);
    QString fileContent = FileUtils::readFile(filePath);

    if (fileContent.isEmpty() && !filePath.isEmpty()) {
        // alert
    }

    handleTabs->addNewTab(fileName, fileContent);

}

void MainWindow::on_actionSave_triggered() {
    fs->saveFile();
}


void MainWindow::on_actionSave_as_triggered() {
    fs->saveAsFile();
}

