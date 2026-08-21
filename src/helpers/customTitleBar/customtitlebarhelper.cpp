#include "customtitlebarhelper.h"

CustomTitleBarHelper::CustomTitleBarHelper(QWidget *parent) {}

bool CustomTitleBarHelper::handleMaximizePressed() {
    if (window()->isMaximized()) {
        window()->showNormal();
        return true; // The window is not maximized
    } else {
        window()->showMaximized();
        return false; // The window is maximized
    }
}