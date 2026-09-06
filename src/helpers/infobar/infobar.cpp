#include "infobar.h"

void InfoBar::setPath(const QString& path, int indexTab) {
    tabsData[indexTab].path = path;
}
QString InfoBar::getPath(int indexTab) {
    return tabsData.value(indexTab).path;
}

void InfoBar::setNotification(const QString &notif, int indexTab) {
    tabsData[indexTab].notification = notif;
}
QString InfoBar::getNotification(int indexTab) {
    return tabsData.value(indexTab).notification;
}
