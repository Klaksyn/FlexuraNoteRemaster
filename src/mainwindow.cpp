#include <QWidget>
#include <QLabel>
#include <QProcess>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QClipboard>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qfiledialog.h"

#include "helpers/tabs/handletabs.h"
#include "helpers/fs/fs.h"
#include "helpers/fs/fileutils.h"
#include "helpers/alerts/alerts.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabsClosable(true);

    handleTabs = std::make_unique<HandleTabs>(ui->tabWidget);
    fs = std::make_unique<FS>(this, ui->tabWidget, ui->plainTextEdit);
    text = std::make_unique<Text>(ui->plainTextEdit);

    Alerts::setDefaultParent(this);

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
// Like "New File" but just creating a new tab
void MainWindow::on_actionNewFileIcon_triggered() { // icon
    handleTabs->addNewTab();
}

void MainWindow::on_actionOpen_triggered() {
    fs->openFile();
}
void MainWindow::on_actionOpenFileIcon_triggered() {
    fs->openFile();
}

void MainWindow::on_actionSave_triggered() {
    fs->saveFile();
}
void MainWindow::on_actionSaveFileIcon_triggered() {
    fs->saveFile();
}


void MainWindow::on_actionSave_as_triggered() {
    fs->saveAsFile();
}
void MainWindow::on_actionSaveAsFileIcon_triggered() {
    fs->saveAsFile();
}


//==========================================================
//                          Work with text
//==========================================================
void MainWindow::on_actionCopyTextIcon_triggered() {
    text->copySelectedText();
}

