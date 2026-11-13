#pragma once

#include <QString>

namespace FileUtils {
    QString readFile(const QString& filePath);
    QString getFileName(const QString& filePath);
    QString shortenPath(const QString& fullPath, int keepFolders = 3);
}