#include "fs.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QProcess>

#include "../alerts/alerts.h"
#include "fileutils.h"

FS::FS(QWidget* parent,
       HandleTabs* handleTabs,
       QPlainTextEdit* plainTextEdit,
       InfoBar* infoBar) {

    this->parent = parent;
    this->handleTabs = handleTabs;
    this->plainTextEdit = plainTextEdit;
    this->infoBar = infoBar;
    this->fullPathToFile = new QString();
}

FS::~FS() {
    delete fullPathToFile;
}

//==========================================================
//                          Open
//==========================================================
void FS::openFile() {
    QString filePath = QFileDialog::getOpenFileName(parent,
                    "open text file","","Text Files(*.txt);;All Files(*)");

    if (filePath.isEmpty())
        return;

    QString fileName = FileUtils::getFileName(filePath);
    QString fileContent = FileUtils::readFile(filePath);

    handleTabs->addNewTab(fileName, fileContent);

    int currentIndexTab = handleTabs->getIndexCurrentTab();

    handleTabs->setNameTab(currentIndexTab, FileUtils::getFileName(filePath));

    infoBar->setPath(FileUtils::shortenPath(filePath), currentIndexTab);
    setFullPath(filePath);
}

void FS::openInFileExplorer(const QString &filePath) {
    QFileInfo fileInfo(filePath);

#if defined(Q_OS_WIN)
    QStringList args;

    if (!fileInfo.isDir()) {
        args << "/select,";
    }

    args << QDir::toNativeSeparators(filePath);
    QProcess::startDetached("explorer.exe", args);
#elif defined(Q_OS_MAC)
    QStringList args;
    args << "-e" << QString("tell application \"Finder\" to reveal POSIX file \"%1\"").arg(filePath);
    QProcess::execute("/usr/bin/osascript", args);
    args.clear();
    args << "-e" << "tell application \"Finder\" to activate";
    QProcess::execute("/usr/bin/osascript", args);

#else
    // Linux: GNOME/Nautilus, KDE/Dolphin and etc
    QStringList args;
    args << "--session" << "--dest=org.freedesktop.FileManager1"
         << "--type=method_call" << "/org/freedesktop/FileManager1"
         << "org.freedesktop.FileManager1.ShowItems"
         << QString("array:string:file://%1").arg(fileInfo.absoluteFilePath())
         << "string:";
    if (!QProcess::startDetached("dbus-send", args)) {
        // Резервный вариант: просто открыть родительскую папку
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absolutePath()));
    }
#endif

}


//==========================================================
//                          Save
//==========================================================
void FS::saveFile() {
    QString text = plainTextEdit->toPlainText();

    if (infoBar->getPath(handleTabs->getIndexCurrentTab()).isEmpty()) {
        saveAsFile();
        return;
    }

    QFile file(infoBar->getPath(handleTabs->getIndexCurrentTab()));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //Alerts::critical("ERROR", "Could not open file for writing!");
        return;
    }

    QTextStream out(&file);
    out << text;

    file.close();

}

void FS::saveAsFile() {
    QString text = plainTextEdit->toPlainText();

    QString filePath = QFileDialog::getSaveFileName(parent,
            "save text file", "", "Text files(*.txt);;All files(*)");

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //Alerts::critical("ERROR", "Could not open file for writing!");
        return;
    }

    QTextStream out(&file);
    out << text;

    file.close();

    handleTabs->setNameTab(handleTabs->getIndexCurrentTab(), FileUtils::getFileName(filePath));
    infoBar->setPath(filePath, handleTabs->getIndexCurrentTab());
    setFullPath(filePath);


}

//==========================================================
//                          Full Path
//==========================================================
void FS::setFullPath(const QString& path) {
    if (fullPathToFile != &path && fullPathToFile != nullptr)
        *fullPathToFile = path;
}

QString FS::getFullPath() {
    return fullPathToFile ? *fullPathToFile : QString();
}


