#pragma once

#include <QString>

namespace FS {
    QString readFile(const QString& filePath);
    void saveFile();
    void saveAsFile();

    QString getFileName(const QString& filePath);
}

