#pragma once

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:

    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

    void showFindDialog();
    bool isCurrentlyVisible() const;

private slots:
    void on_btnClose_clicked();

    void on_btnFindNext_clicked();

    void on_checkBoxCaseSens_stateChanged(int arg1);

    void on_checkBoxTextWrap_stateChanged(int arg1);

    void on_checkBoxSearchWholeWords_stateChanged(int arg1);

    void on_radioButtonTop_clicked(bool checked);

    void on_radioButtonDown_clicked(bool checked);

private:
    bool m_isCaseSens = false;
    bool m_isTextWrap = false;
    bool m_isSearchWholeWords = false;
    bool m_isDirectTop = false;
    bool m_isDirectDown = false;

    Ui::FindDialog *ui;
};

