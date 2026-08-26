#include "fs.h"

#include <QFile>
#include <QFileInfo>

QString FS::readFile(const QString &filePath) {
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

QString FS::getFileName(const QString &filePath) {
    if (filePath.isEmpty()) {
        return "";
    }

    QFileInfo fileInfo(filePath);

    return fileInfo.fileName();
}
