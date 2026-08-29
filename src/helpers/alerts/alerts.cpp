#include "alerts.h"

#include <QMessageBox>
#include <QWidget>

#include "../log/log.h"

namespace {
    QWidget* g_defaultParent = nullptr;

    bool isParentSet() {
        if (g_defaultParent == nullptr) {
            Log::error("Alerts::setDefaultParent() was not called before showing an alert!");
            return false;
        }

        return true;
    }
}

void Alerts::setDefaultParent(QWidget *parent) {
    g_defaultParent = parent;
}

void Alerts::info(const QString &title, const QString &text) {
    if (!isParentSet()) return;

    QMessageBox::information(g_defaultParent, title, text);
}

void Alerts::warning(const QString &title, const QString &text) {
    if (!isParentSet()) return;

    QMessageBox::warning(g_defaultParent, title, text);
}

void Alerts::critical(const QString &title, const QString &text) {
    if (!isParentSet()) return;

    QMessageBox::critical(g_defaultParent, title, text);
}