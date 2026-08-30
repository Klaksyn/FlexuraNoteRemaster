#pragma once

#include <QString>
#include <QPlainTextEdit>

class Text {

public:
    Text(QPlainTextEdit* plainTextEdit);

    void copy();
    void paste();
    void cut();

    void undo();
    void redo();

private:
    bool isPlainTextEditSet();

    QPlainTextEdit* m_plainText = nullptr;
};
