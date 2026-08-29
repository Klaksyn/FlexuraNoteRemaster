#include "fs.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include "../alerts/alerts.h"
#include "fileutils.h"

FS::FS(QWidget* parent,
       QTabWidget* tabWidget,
       QPlainTextEdit* plainTextEdit) {
    this->parent = parent;
    this->plainTextEdit = plainTextEdit;

    handleTabs = std::make_unique<HandleTabs>(tabWidget);
    Alerts::setDefaultParent(parent);

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
    handleTabs->setNameTab(handleTabs->getIndexCurrentTab(), FileUtils::getFileName(filePath));
}


//==========================================================
//                          Save
//==========================================================
void FS::saveFile() {
    QString text = plainTextEdit->toPlainText();

    if (infoBar.path.isEmpty()) {
        saveAsFile();
        return;
    }

    QFile file(infoBar.path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        Alerts::critical("ERROR", "Could not open file for writing!");
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
        Alerts::critical("ERROR", "Could not open file for writing!");
        return;
    }

    QTextStream out(&file);
    out << text;

    file.close();

    handleTabs->setNameTab(handleTabs->getIndexCurrentTab(), FileUtils::getFileName(filePath));
    infoBar.path = filePath;
}




