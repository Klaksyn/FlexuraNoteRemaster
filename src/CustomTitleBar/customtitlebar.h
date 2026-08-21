#pragma once

#include <QWidget>
#include <QTabBar>
#include <QPushButton>
#include <QHBoxLayout>

class CustomTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTitleBar(QWidget *parent = nullptr);

    QTabBar* tabBar() const { return m_tabBar; }

    QPushButton *getMaximizeButton() const { return m_maximizeBtn; }

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    QTabBar     *m_tabBar;
    QPushButton *m_minimizeBtn;
    QPushButton *m_maximizeBtn;
    QPushButton *m_closeBtn;
    QPoint       m_dragPosition;

};

