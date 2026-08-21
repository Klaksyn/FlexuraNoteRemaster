#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CustomTitleBar/customtitlebar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    auto *titleBar = new CustomTitleBar(this);
    m_stackedWidget = new QStackedWidget(this);

    m_stackedWidget->addWidget(new QWidget(this));
    m_stackedWidget->addWidget(new QWidget(this));

    connect(titleBar->tabBar(), &QTabBar::currentChanged, this, [this](int index) {
        m_stackedWidget->setCurrentIndex(index);
    });

    QWidget *originalCentral = centralWidget();

    auto *wrapper = new QWidget(this);
    auto *layout = new QVBoxLayout(wrapper);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(titleBar);
    layout->addWidget(originalCentral);


    setCentralWidget(wrapper);


}

MainWindow::~MainWindow()
{
    delete ui;
}
