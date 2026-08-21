#include "mainwindow.h"

#include "helpers/style_loader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString combinedStyle = loadStyleFile("../../UI/styles/tab.qss");

    a.setStyleSheet(combinedStyle);

    MainWindow w;
    w.show();
    return QApplication::exec();
}
