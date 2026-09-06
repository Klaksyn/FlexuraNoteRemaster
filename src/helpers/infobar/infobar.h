#pragma once

#include <QString>
#include <QMap>

struct TabInfo {
    QString path;
    QString notification = "none";
    QString encoding = "none";

    int length = 0;
    int lines = 0;
    int ln = 0;
    int col = 0;
    int pos = 0;
    int zoom = 0;
};

class InfoBar
{
public:
    void changeIndexTab(int from, int to);

    void setPath(const QString& path, int indexTab);
    QString getPath(int indexTab);

    void setNotification(const QString& notif, int indexTab);
    QString getNotification(int indexTab);

    void setEncoding(const QString& enc, int indexTab);
    QString getEncoding(int indexTab);

    void setLength(int length, int indexTab);
    int getLength(int indexTab);

    void setLines(int lines, int indexTab);
    int getLines(int indexTab);

    void setLn(int ln, int indexTab);
    int getLn(int indexTab);

    void setCol(int col, int indexTab);
    int getCol(int indexTab);

    void setPos(int pos, int indexTab);
    int getPos(int indexTab);

    void setZoom(int zoom, int indexTab);
    int getZoom(int indexTab);

    void removeTab(int indexTab);

private:
    QMap<int, TabInfo> tabsData;
};

