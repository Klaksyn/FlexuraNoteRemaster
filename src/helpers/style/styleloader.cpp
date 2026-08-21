#include "styleloader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

QString loadStyleFile(const QString &pathStyle) {

    QFile styleFile(pathStyle);

    if (!styleFile.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "[ERROR_LOAD_STYLE] Failed to load: " << styleFile.errorString();
        return QString();
    }

    QTextStream ts(&styleFile);
    QString content = ts.readAll();
    styleFile.close();

    return content;
}
