#include "mainwindow.h"

#include "helpers/style/styleloader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString combinedStyle = loadStyleFile(":res/UI/styles/tab.qss")
                            + loadStyleFile(":res/UI/styles/btnTitleBar.qss");

    a.setStyleSheet(combinedStyle);

    MainWindow w;
    w.show();
    return QApplication::exec();
}
