#include "finddialog.h"
#include "ui_finddialog.h"

#include <QTextDocument>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    connect(ui->textEdit->document(), &QTextDocument::contentsChanged, this, [this]() {
        bool isEmpty = ui->textEdit->document()->isEmpty();
        ui->btnFindNext->setEnabled(!isEmpty);
    });

}

FindDialog::~FindDialog()
{
    delete ui;
}


void FindDialog::showFindDialog()
{
    this->show();
    this->raise();
    this->activateWindow();
}
bool FindDialog::isCurrentlyVisible() const
{
    return this->isVisible();
}


void FindDialog::on_btnClose_clicked()
{
    this->close();
}


void FindDialog::on_btnFindNext_clicked()
{

}

//==============================
// Triggers the search query
// based on current input fields
//==============================
void FindDialog::on_checkBoxCaseSens_stateChanged(int arg1)
{
    this->m_isCaseSens = (arg1 == Qt::Checked);
}


void FindDialog::on_checkBoxTextWrap_stateChanged(int arg1)
{
    this->m_isTextWrap = (arg1 == Qt::Checked);
}


void FindDialog::on_checkBoxSearchWholeWords_stateChanged(int arg1)
{
    this->m_isSearchWholeWords = (arg1 == Qt::Checked);
}


void FindDialog::on_radioButtonTop_clicked(bool checked)
{
    this->m_isDirectTop = checked;
}

void FindDialog::on_radioButtonDown_clicked(bool checked)
{
    this->m_isDirectDown = checked;
}

