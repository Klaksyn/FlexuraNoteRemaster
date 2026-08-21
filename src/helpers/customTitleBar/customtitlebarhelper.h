#pragma once

#include <QWidget>
#include <QPushButton>

class CustomTitleBarHelper : public QWidget {
    Q_OBJECT

public:
    explicit CustomTitleBarHelper(QWidget *parent = nullptr);

    bool handleMaximizePressed();

};