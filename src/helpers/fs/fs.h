#pragma once

#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QMap>

#include "../../infobar.h"
#include "../tabs/handletabs.h"

class FS {
public:
    FS(QWidget* parent, HandleTabs* handleTabs, QPlainTextEdit* plainTextEdit);

    void openFile();

    void saveFile();
    void saveAsFile();

private:
    QWidget* parent = nullptr;
    QPlainTextEdit* plainTextEdit = nullptr;
    HandleTabs* handleTabs;

    InfoBar infoBar;
};
