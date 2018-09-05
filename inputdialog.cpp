#include "inputdialog.h"        //Including class declaration.
#include "ui_inputdialog.h"
#include <QMessageBox>          //Class for any dialog boxes to give the user information/to ask a question.
#include <QDebug>               //Class that allows for output; for testing purposes.

//Constructor
inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent), //Superclass constructor
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);

    //Signal-slot mechanism - connecting the buttons on the dialog to the dialog itself.
    connect(ui->confirmButton, &QPushButton::clicked, this, &inputDialog::confirm_Pressed);
    connect(ui->cancelButton, &QPushButton::clicked, this, &inputDialog::cancel_Pressed);

    //Connecting the spin boxes on the window to changeFee, which changes the value of the fee display.
    connect(ui->minBox, SIGNAL(valueChanged(int)), this, SLOT(changeFee()));
    connect(ui->hrBox, SIGNAL(valueChanged(int)), this, SLOT(changeFee()));

    this->setWindowTitle("Reservation Information");
}

//Destructor
inputDialog::~inputDialog()
{
    delete ui;
}

//Defining slot - executed when 'Confirm' button is pressed.
void inputDialog::confirm_Pressed()
{
    //Using a QMessageBox to ask the user if they want to confirm their reservation.
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm", "Confirm reservation?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (confirm == QMessageBox::Yes)
    {
        //Retrieving values from the user inputs; these will be in turn retrieved by the spot object.
        temp_ID = ui->lineEdit->text();
        temp_hr = ui->hrBox->value();
        temp_min= ui->minBox->value();

        sstatus = true;

        //Emits this signal so that the spot can do something upon receiving.
        emit Reserved();

        this->close();
    }
}

//Defining slot - executed when 'Cancel' button is pressed.
void inputDialog::cancel_Pressed()
{
    QMessageBox::StandardButton cancel;
    cancel = QMessageBox::question(this, "Cancel Reservation", "Do you wish to cancel?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (cancel == QMessageBox::Yes)
    {
        this->close();
    }
}

//Defining slot - executed when values of the spin buttons has been changed.
void inputDialog::changeFee()
{

    int min = ui->minBox->value();
    int hr = ui->hrBox->value();
    int periodFee = 15;
    ui->moneyLabel->setNum((hr*60+min)/periodFee); //Setting the value of the fee display.
}
