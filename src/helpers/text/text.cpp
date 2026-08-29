#include "text.h"

#include <QClipboard>

#include "../log/log.h"

Text::Text(QPlainTextEdit* plainTextEdit) {
    m_plainText = plainTextEdit;
}

bool Text::isParentSet() {
    if (m_plainText == nullptr) {
        Log::error("Text::Text(parent) was not called before using Text!");
        return false;
    }

    return true;
}

void Text::copySelectedText() {
    QString selectedText = m_plainText->textCursor().selectedText();

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(selectedText);
}