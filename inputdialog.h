#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>              //Base class for all dialog windows.
#include <QString>              //String class for Qt

namespace Ui {
class inputDialog;
}

class inputDialog : public QDialog //Inheriting the properties of all dialog windows.
{
    Q_OBJECT //Q_OBJECT macro - refer to mainwindow.h.

public:
    //Constructor
    explicit inputDialog(QWidget *parent = 0);

    //Destructor
    ~inputDialog();

    //Temporary variables created so that values can be transferred to the spot objects.
    QString temp_ID;
    int temp_hr, temp_min;

    bool sstatus;

signals:
    //Emitted when the user clicks confirm on the reservation.
    void Reserved();

private:
    Ui::inputDialog *ui;

private slots:
    //Executed when certain buttons are pressed.
    void confirm_Pressed();
    void cancel_Pressed();

    //Changes the fee display based on user input.
    void changeFee();
};

#endif // INPUTDIALOG_H
