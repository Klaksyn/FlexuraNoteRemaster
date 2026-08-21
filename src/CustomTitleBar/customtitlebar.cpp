#include "customtitlebar.h"
#include "../helpers/customTitleBar/customtitlebarhelper.h"

#include <QMouseEvent>

CustomTitleBar::CustomTitleBar(QWidget *parent) : QWidget(parent) {

    CustomTitleBarHelper *helper = new CustomTitleBarHelper(this);

    setFixedHeight(36);

    m_tabBar = new QTabBar(this);
    m_tabBar->setTabsClosable(true);
    m_tabBar->setDocumentMode(true);
    m_tabBar->setExpanding(false);

    m_minimizeBtn = new QPushButton("—", this);
    m_maximizeBtn = new QPushButton("☐", this);
    m_closeBtn = new QPushButton("✕", this);

    m_minimizeBtn->setObjectName("minimizeBtn");
    m_maximizeBtn->setObjectName("maximizeBtn");
    m_closeBtn->setObjectName("closeBtn");

    for (auto* btn : {m_minimizeBtn, m_maximizeBtn, m_closeBtn}) {
        btn->setFixedSize(46, 36);
        btn->setFlat(true);
    }

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(m_tabBar);
    layout->addStretch();
    layout->addWidget(m_minimizeBtn);
    layout->addWidget(m_maximizeBtn);
    layout->addWidget(m_closeBtn);

    connect(m_minimizeBtn, &QPushButton::clicked, this, [this]{
        window()->showMinimized();
    });

    connect(m_maximizeBtn, &QPushButton::clicked, this, [this, helper]{
        bool isMaximized = helper->handleMaximizePressed();
        m_maximizeBtn->setText(isMaximized ? "🗗" : "☐");
    });

    connect(m_closeBtn, &QPushButton::clicked, this, [this]{
        window()->close();
    });
}

// Dragging the window behind the title bar
void CustomTitleBar::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPosition().toPoint() - window()->frameGeometry().topLeft();
        event->accept();
    }
}

void CustomTitleBar::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        window()->move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

// When you double‑click the window, it expands to fill the entire screen.
void CustomTitleBar::mouseDoubleClickEvent(QMouseEvent *event) {
    CustomTitleBarHelper *helper = new CustomTitleBarHelper(this);

    if (event->button() == Qt::LeftButton) {
        bool isMaximized = helper->handleMaximizePressed();
        m_maximizeBtn->setText(isMaximized ? "🗗" : "☐");
    }
}