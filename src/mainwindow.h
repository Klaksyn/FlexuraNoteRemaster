#pragma once

#include "customTitleBar/customtitlebar.h"

#include <QMainWindow>
#include <QStackedWidget>

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

protected:
    // Intercepting Windows system events (for Snap Layouts)
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);


private:
    Ui::MainWindow *ui;
    QStackedWidget *m_stackedWidget;
    CustomTitleBar *m_titleBar;
};

