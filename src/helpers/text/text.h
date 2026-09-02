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

    void selectAll();
    void deleteAll();

private:
    bool isPlainTextEditSet();

    QPlainTextEdit* m_plainText = nullptr;
};
