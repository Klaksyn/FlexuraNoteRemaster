#include <QWidget>
#include <QLabel>
#include <QProcess>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QClipboard>
#include <QShortcut>
#include <QKeySequence>

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
    fs = std::make_unique<FS>(this, handleTabs.get(), ui->plainTextEdit);
    text = std::make_unique<Text>(ui->plainTextEdit);

    Alerts::setDefaultParent(this);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::onTabCloseRequested);

    // hotkey managment
    // in dev
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
//                          Work With Application
//==========================================================
void MainWindow::on_actionNew_window_triggered() {
    QString programPath = QCoreApplication::applicationFilePath();

    QProcess::startDetached(programPath, QStringList());
}

void MainWindow::on_actionExit_triggered() {
    this->close();
}

//==========================================================
//                          File
//==========================================================
// Like "New File" but just creating a new tab
void MainWindow::on_actionNewFileIcon_triggered() {
    handleTabs->addNewTab();
}

void MainWindow::on_actionOpen_triggered() {
    fs->openFile();
}
void MainWindow::on_actionOpenFileIcon_triggered() {
    on_actionOpen_triggered();
}

void MainWindow::on_actionSave_triggered() {
    fs->saveFile();
}
void MainWindow::on_actionSaveFileIcon_triggered() {
    on_actionSave_triggered();
}


void MainWindow::on_actionSave_as_triggered() {
    fs->saveAsFile();
}
void MainWindow::on_actionSaveAsFileIcon_triggered() {
    on_actionSave_as_triggered();
}


//==========================================================
//                          Work with text
//==========================================================
void MainWindow::on_actionCopy_triggered() {
    text->copy();
}
void MainWindow::on_actionCopyTextIcon_triggered() {
    on_actionCopy_triggered();
}


void MainWindow::on_actionPaste_triggered() {
    text->paste();
}
void MainWindow::on_actionPasteTextIcon_triggered() {
    on_actionPasteTextIcon_triggered();
}


void MainWindow::on_actionCut_triggered() {
    text->cut();
}
void MainWindow::on_actionCutTextIcon_triggered() {
    on_actionCut_triggered();
}


void MainWindow::on_actionUndo_triggered() {
    text->undo();
}
void MainWindow::on_actionUndoIcon_triggered() {
    on_actionUndoIcon_triggered();
}


void MainWindow::on_actionRedo_triggered() {
    text->redo();
}
void MainWindow::on_actionRedoIcon_triggered() {
    on_actionRedo_triggered();
}


void MainWindow::on_actionSelect_all_triggered() {
    text->selectAll();
}

void MainWindow::on_actionDelete_all_triggered() {
    QString textQuest = "Are you sure you want to clear the text without recovery?";

    if (Alerts::questYesOrNo("Delete All Text", textQuest))
        text->deleteAll();
}

