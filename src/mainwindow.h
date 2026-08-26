#pragma once

#include "helpers/tabs/handletabs.h"
#include "helpers/fs/fs.h"

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

private:
    Ui::MainWindow *ui;
    std::unique_ptr<HandleTabs> handleTabs;
};

