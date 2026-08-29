#include "log.h"

#include <QDebug>

void Log::info(const QString &text) {
    qDebug() << "[INFO] " << text;
}

void Log::error(const QString& text) {
    qDebug() << "[ERROR] " << text;
}

void Log::warning(const QString &text) {
    qDebug() << "[WARNING] " << text;
}
