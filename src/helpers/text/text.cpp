#include "text.h"

#include <QClipboard>

#include "../log/log.h"

Text::Text(QPlainTextEdit* plainTextEdit) {
    m_plainText = plainTextEdit;
}

bool Text::isPlainTextEditSet() {
    if (m_plainText == nullptr) {
        Log::error("Text::Text(parent) was not called before using Text!");
        return false;
    }

    return true;
}

void Text::copy() {
    if (!isPlainTextEditSet()) return;

    m_plainText->copy();
}
void Text::paste() {
    if (!isPlainTextEditSet()) return;

    m_plainText->paste();
}
void Text::cut() {
    if (!isPlainTextEditSet()) return;

    m_plainText->cut();
}

void Text::undo() {
    if (!isPlainTextEditSet()) return;

    m_plainText->undo();
}

void Text::redo() {
    if (!isPlainTextEditSet()) return;

    m_plainText->redo();
}

void Text::selectAll() {
    if (!isPlainTextEditSet()) return;

    m_plainText->selectAll();
}
void Text::deleteAll() {
    if (!isPlainTextEditSet()) return;

    m_plainText->clear();
}

