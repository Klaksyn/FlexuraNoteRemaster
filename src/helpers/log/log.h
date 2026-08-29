#pragma once

#include <QString>

namespace Log {
    void warning(const QString& text);
    void error(const QString& text);
    void info(const QString& text);
}