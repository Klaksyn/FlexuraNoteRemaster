#pragma once

#include <QString>

struct InfoBar {
    int length = 0;
    int lines = 0;
    int ln = 0;
    int col = 0;
    int pos = 0;
    int zoom = 0;

    QString path;
    QString notification = "none";
    QString encoding = "none";
};

