#include "fileutils.h"

#include <QFile>
#include <QTextStream>
#include <QFileInfo>

QString FileUtils::readFile(const QString &filePath) {
    if (filePath.isEmpty()) {
        return "";
    }

    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();

        return fileContent;
    }

    // here alert
    return "";
}

QString FileUtils::getFileName(const QString &filePath) {
    if (filePath.isEmpty()) {
        return "";
    }

    QFileInfo fileInfo(filePath);

    return fileInfo.fileName();
}