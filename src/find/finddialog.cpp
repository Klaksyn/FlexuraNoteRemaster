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

