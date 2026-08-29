#pragma once

#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QPlainTextEdit>

#include "../../infobar.h"
#include "../tabs/handletabs.h"

class FS {
public:
    FS(QWidget* parent, QTabWidget* tabWidget, QPlainTextEdit* plainTextEdit);

    void openFile();

    void saveFile();
    void saveAsFile();

private:
    QWidget* parent = nullptr;
    QPlainTextEdit* plainTextEdit = nullptr;

    InfoBar infoBar;
    std::unique_ptr<HandleTabs> handleTabs;
};
