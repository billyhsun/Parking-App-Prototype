#include "checkdialog.h"
#include "ui_checkdialog.h"
#include <QMessageBox>

checkDialog::checkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkDialog)
{
    ui->setupUi(this);

    connect(ui->okButton, &QPushButton::clicked, this, &checkDialog::ok_Clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &checkDialog::cancel_Clicked);
}

checkDialog::~checkDialog()
{
    delete ui;
}

void checkDialog::ok_Clicked()
{
    QMessageBox::StandardButton check;
    check = QMessageBox::question(this, "Check/Remove car", "Some information...\nWould you like to remove your car?",
                                  QMessageBox::Yes | QMessageBox::No);
}

void checkDialog::cancel_Clicked()
{
    this->close();
}
