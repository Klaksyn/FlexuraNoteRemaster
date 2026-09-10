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

private:
    Ui::FindDialog *ui;
};

