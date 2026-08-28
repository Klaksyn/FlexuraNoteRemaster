#pragma once

#include <QString>
#include <QWidget>
#include <QPlainTextEdit>

#include "../../infobar.h"

class FS {
public:
    FS(QWidget* parent, QPlainTextEdit* plainTextEdit);

    void saveFile();
    void saveAsFile();

private:
    QWidget* parent = nullptr;
    QPlainTextEdit* plainTextEdit = nullptr;

    InfoBar infoBar;
};
