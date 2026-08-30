#pragma once

#include "helpers/tabs/handletabs.h"
#include "helpers/fs/fs.h"
#include "helpers/text/text.h"

#include "infobar.h"

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionNew_Tab_triggered();

    void onTabCloseRequested(int index);
    void on_actionClose_the_window_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_window_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionOpenFileIcon_triggered();

    void on_actionSaveFileIcon_triggered();

    void on_actionSaveAsFileIcon_triggered();

    void on_actionNewFileIcon_triggered();

    void on_actionCopyTextIcon_triggered();

    void on_actionPasteTextIcon_triggered();

    void on_actionCutTextIcon_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<HandleTabs> handleTabs;
    std::unique_ptr<FS> fs;
    std::unique_ptr<Text> text;

    InfoBar infoBar;

};

