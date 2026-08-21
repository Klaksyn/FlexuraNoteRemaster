#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CustomTitleBar/customtitlebar.h"

#ifdef Q_OS_WIN
    #include <windows.h>
    #include <windowsx.h>
    #include <dwmapi.h>
    #pragma comment(lib, "dwmapi.lib")
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (this->menuBar()) {
        this->setMenuBar(nullptr);
    }

    m_titleBar = new CustomTitleBar(this);
    m_stackedWidget = new QStackedWidget(this);

    m_stackedWidget->addWidget(new QWidget(this));
    m_stackedWidget->addWidget(new QWidget(this));

    connect(m_titleBar->tabBar(), &QTabBar::currentChanged, this, [this](int index) {
        m_stackedWidget->setCurrentIndex(index);
    });

    QWidget *originalCentral = centralWidget();

    auto *wrapper = new QWidget(this);
    auto *layout = new QVBoxLayout(wrapper);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(m_titleBar);
    layout->addWidget(originalCentral);


    setCentralWidget(wrapper);

#ifdef Q_OS_WIN
    HWND hwnd = (HWND)this->winId();
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    // Add frame flags so that Snap Layouts work and Maximize is implemented correctly
    SetWindowLong(hwnd, GWL_STYLE, style | WS_THICKFRAME | WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX);

    // Stretch the window to cover the entire non-client area
    MARGINS margins = {0, 0, 0, 0};
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    // Forcibly update the window position to apply WinAPI styles
    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
#else
    setWindowFlag(Qt::FramelessWindowHint);
#endif



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
#ifdef Q_OS_WIN
    MSG *msg = static_cast<MSG*>(message);

    if (msg->message == WM_NCCALCSIZE && msg->wParam == TRUE) {
        *result = 0;
        return true;
    }


    if (msg->message == WM_NCHITTEST) {
        int x = GET_X_LPARAM(msg->lParam);
        int y = GET_Y_LPARAM(msg->lParam);
        QPoint localPos = this->mapFromGlobal(QPoint(x, y));

        // Resizing the window beyond the edges
        const int borderSize = 6;
        bool isLeft   = localPos.x() < borderSize;
        bool isRight  = localPos.x() > this->width() - borderSize;
        bool isTop    = localPos.y() < borderSize;
        bool isBottom = localPos.y() > this->height() - borderSize;

        if (isTop && isLeft)     { *result = HTTOPLEFT;     return true; }
        if (isTop && isRight)    { *result = HTTOPRIGHT;    return true; }
        if (isBottom && isLeft)  { *result = HTBOTTOMLEFT;  return true; }
        if (isBottom && isRight) { *result = HTBOTTOMRIGHT; return true; }
        if (isLeft)              { *result = HTLEFT;        return true; }
        if (isRight)             { *result = HTRIGHT;       return true; }
        if (isTop)               { *result = HTTOP;         return true; }
        if (isBottom)            { *result = HTBOTTOM;      return true; }

        // Dragging the window beyond the CustomTitleBar
        if (m_titleBar) {
            QPoint titleBarPos = m_titleBar->mapFromGlobal(QPoint(x, y));
            if (m_titleBar->rect().contains(titleBarPos)) {
                QWidget *child = m_titleBar->childAt(titleBarPos);
                if (!child || (!qobject_cast<QPushButton*>(child) && !qobject_cast<QTabBar*>(child))) {
                    *result = HTCAPTION;
                    return true;
                }
            }
        }

        if (msg->message == WM_WINDOWPOSCHANGING || msg->message == WM_GETMINMAXINFO) {
            HWND hwnd = (HWND)this->winId();
            DWORD style = GetWindowLong(hwnd, GWL_STYLE);
            if (style & WS_CAPTION) {
                // If Windows tried to return WS_CAPTION, we put it back on the fly.
                SetWindowLong(hwnd, GWL_STYLE, style & ~WS_CAPTION);
            }
        }
    }
#endif
    return QMainWindow::nativeEvent(eventType, message, result);
}


