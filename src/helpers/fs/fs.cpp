#include "fs.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

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

    infoBar->setPath(filePath, handleTabs->getIndexCurrentTab());
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

}




