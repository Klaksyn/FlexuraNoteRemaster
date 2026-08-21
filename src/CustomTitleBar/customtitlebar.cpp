#include "customtitlebar.h"

#include <QMouseEvent>

CustomTitleBar::CustomTitleBar(QWidget *parent) : QWidget(parent) {

    setFixedHeight(36);

    m_tabBar = new QTabBar(this);
    m_tabBar->setTabsClosable(true);
    m_tabBar->setDocumentMode(true);
    m_tabBar->setExpanding(true);

    m_minimizeBtn = new QPushButton("—", this);
    m_maximizeBtn = new QPushButton("☐", this);
    m_closeBtn = new QPushButton("✕", this);

    for (auto* btn : {m_minimizeBtn, m_maximizeBtn, m_closeBtn}) {
        btn->setFixedSize(46, 36);
        btn->setFlat(true);
    }

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_tabBar, 1);
    layout->addStretch();
    layout->addWidget(m_minimizeBtn);
    layout->addWidget(m_maximizeBtn);
    layout->addWidget(m_closeBtn);

    connect(m_minimizeBtn, &QPushButton::clicked, this, [this]{
        window()->showMinimized();
    });

    connect(m_maximizeBtn, &QPushButton::clicked, this, [this]{
        window()->isMaximized() ? window()->showNormal() : window()->showMaximized();
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