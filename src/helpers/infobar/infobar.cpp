#include "infobar.h"

#include "../alerts/alerts.h"

void InfoBar::changeIndexTab(int from, int to) {
    TabInfo moved = tabsData.take(from);

    if (from < to) {
        // shift everything between from+1 and to one position to the left
        for (int i = from + 1; i <= to; ++i) {
            if (tabsData.contains(i)) {
                tabsData.insert(i - 1, tabsData.take(i));
            }
        }
    } else {
        // shift everything between to and from-1 one position to the right
        for (int i = from - 1; i >= to; --i) {
            if (tabsData.contains(i)) {
                tabsData.insert(i + 1, tabsData.take(i));
            }
        }
    }

    tabsData.insert(to, moved);
}

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
