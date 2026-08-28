#include "fs.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

FS::FS(QWidget* parent,
       QPlainTextEdit* plainTextEdit) {
    this->parent = parent;
    this->plainTextEdit = plainTextEdit;
}


//==========================================================
//                          Save
//==========================================================
void FS::saveFile() {
    if (parent == nullptr || plainTextEdit == nullptr) {
        qDebug() << "Please provide a valid parameters in the FS constructor!";
        return;
    }

    QString text = plainTextEdit->toPlainText();

    if (infoBar.path.isEmpty()) {
        saveAsFile();
        return;
    }

    QFile file(infoBar.path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // alert: Could not open file for writing
    }

    QTextStream out(&file);
    out << text;

    file.close();
}

void FS::saveAsFile() {

    if (parent == nullptr || plainTextEdit == nullptr) {
        qDebug() << "Please provide a valid parameters in the FS constructor!";
        return;
    }

    QString text = plainTextEdit->toPlainText();

    QString filePath = QFileDialog::getSaveFileName(parent,
            "save text file", "", "Text files(*.txt);;All files(*)");

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // alert: Could not open file for writing
    }

    QTextStream out(&file);
    out << text;

    file.close();

    infoBar.path = filePath;
}




