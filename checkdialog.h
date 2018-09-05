#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H

#include <QDialog>

namespace Ui {
class checkDialog;
}

class checkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit checkDialog(QWidget *parent = 0);
    ~checkDialog();

private:
    Ui::checkDialog *ui;

private slots:
    void ok_Clicked();
    void cancel_Clicked();
};

#endif // CHECKDIALOG_H
