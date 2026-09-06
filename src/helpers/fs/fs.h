#pragma once

#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QMap>

#include "../infobar/infobar.h"
#include "../tabs/handletabs.h"

class FS {
public:
    FS(QWidget* parent, HandleTabs* handleTabs, QPlainTextEdit* plainTextEdit, InfoBar* infoBar);

    void openFile();

    void saveFile();
    void saveAsFile();

private:
    QWidget* parent = nullptr;
    QPlainTextEdit* plainTextEdit = nullptr;
    HandleTabs* handleTabs = nullptr;

    InfoBar* infoBar = nullptr;
};
