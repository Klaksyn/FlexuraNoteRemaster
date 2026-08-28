#pragma once

#include <QString>

namespace FileUtils {
    QString readFile(const QString& filePath);
    QString getFileName(const QString& filePath);
}