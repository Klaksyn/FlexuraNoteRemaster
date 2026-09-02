#pragma once

#include <QString>
#include <QWidget>

namespace Alerts {
    void setDefaultParent(QWidget* parent);
    void info(const QString& title, const QString& text);
    void warning(const QString& title, const QString& text);
    void critical(const QString& title, const QString& text);
    bool questYesOrNo(const QString& title, const QString& text);
}
