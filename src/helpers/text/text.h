#pragma once

#include <QString>
#include <QPlainTextEdit>

class Text {

public:
    Text(QPlainTextEdit* plainTextEdit);

    void copySelectedText();

private:
    bool isParentSet();

    QPlainTextEdit* m_plainText = nullptr;
};
