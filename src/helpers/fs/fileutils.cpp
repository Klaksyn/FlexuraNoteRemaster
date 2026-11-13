#include "fileutils.h"

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFileInfo>
#include <QStringList>

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

/**
 * Shorten the file path
 *
 * @brief FileUtils::shortenPath
 * @param fullPath
 * @param keepFolders
 * @return shortenPath
 */
QString FileUtils::shortenPath(const QString &fullPath, int keepFolders) {
    // Standardize slashes to a consistent format '/'
    QString clean = QDir::fromNativeSeparators(fullPath);
    // Split the path by slashes, ignoring empty parts
    QStringList parts = clean.split('/', Qt::SkipEmptyParts);

    // if the path is short, we'll leave it as it is
    if (parts.size() <= keepFolders + 2) {
        if (clean.size() >= 60) {
            return clean.left(clean.size() / 50) + "/../" + QFileInfo(clean).fileName();
        }

        return clean;
    }

    QStringList result = parts.mid(0, keepFolders);

    result.append("..");
    result.append(parts.last());

    return result.join('/');
}

