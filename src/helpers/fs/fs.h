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
    ~FS();

    void openFile();

    void saveFile();
    void saveAsFile();
    void openInFileExplorer(const QString& filePath);

    QString getFullPath();


protected:
    void setFullPath(const QString& path);

private:
    QWidget* parent = nullptr;
    QPlainTextEdit* plainTextEdit = nullptr;
    HandleTabs* handleTabs = nullptr;
    InfoBar* infoBar = nullptr;

    QString* fullPathToFile;
};
