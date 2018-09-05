#include "mainwindow.h"         //Including the class declaration.
#include "ui_mainwindow.h"
#include <QDebug>               //Class that allows for output; for testing purposes.
#include <QMessageBox>          //Class for any dialog boxes to give the user information/to ask a question.
#include <QtCore>               //Core module
#include <QInputDialog>         //Class for a dialog that gets a single piece of information from user.

//Defining the constructor.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //Superclass constructor
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connecting the buttons on the main window to the main window itself - refer to mainwindow.ui.
    //When clicked, the button sends a signal 'clicked'. Upon receiving the signal, the main window will execute its slot.
    connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::check_Clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exit_Clicked);

    //Setting up the graphics scene - a surface for displaying objects.
    scene = new QGraphicsScene(this);

    //graphicsView - a box for displaying graphics - refer to mainwindow.ui.
    ui->graphicsView->setScene(scene);
    this->setWindowTitle("ParkSmart");

    //Creating the parking spot objects.
    //Spots 2-8 all have another spot as parent because they will have the same properties as that spot.
    //More specifically, the positions of those spots are relative to that of their parent spot.
    spot_1 = new SpotIcon;
    spot_2 = new SpotIcon(spot_1);
    spot_3 = new SpotIcon(spot_2);
    spot_4 = new SpotIcon(spot_3);
    spot_5 = new SpotIcon(spot_1);
    spot_6 = new SpotIcon(spot_2);
    spot_7 = new SpotIcon(spot_3);
    spot_8 = new SpotIcon(spot_4);

    //Setting the positions of each spot.
    //Spot 1 - position relative to the graphics scene; all other spots - positions relative to another spot.
    spot_1->setPos(0,0);
    spot_2->setPos(75,0);
    spot_3->setPos(75,0);
    spot_4->setPos(75,0);
    spot_5->setPos(0,75);
    spot_6->setPos(0,75);
    spot_7->setPos(0,75);
    spot_8->setPos(0,75);

    //Adding the items to the scene to be displayed (all other spots are automatically added).
    scene->addItem(spot_1);
}

//Destructor for closing window.
MainWindow::~MainWindow()
{
    delete ui;
}

//Defining check_Clicked - executed when the button to remove a car has been clicked.
void MainWindow::check_Clicked()
{
    //Create a dialog to ask the user to input their driver's liscence.
    Input = QInputDialog::getText(0, "Enter Driver's Liscence", "Driver's Liscence:",QLineEdit::Normal);

    //Assigning each spot's string variable to the value of these variable to user input for comparison purposes.
    spot_1->user_Input = Input;
    spot_2->user_Input = Input;
    spot_3->user_Input = Input;
    spot_4->user_Input = Input;
    spot_5->user_Input = Input;
    spot_6->user_Input = Input;
    spot_7->user_Input = Input;
    spot_8->user_Input = Input;

    //compare_Input - a member function for the SpotIcon class - refer to spoticon.h - that compares the driver's liscence
    //that the user gave when removing their car to the one that was inputted when the car was parked.
    //Although this is done for every spot object, most of what the function does is only executed when the two variables
    //are equal.
    spot_1->compare_Input();
    spot_2->compare_Input();
    spot_3->compare_Input();
    spot_4->compare_Input();
    spot_5->compare_Input();
    spot_6->compare_Input();
    spot_7->compare_Input();
    spot_8->compare_Input();
}

//Defining exit_Clicked slot - executed when the button to exit the application has been clicked.
void MainWindow::exit_Clicked()
{
    //Using a QMessageBox to ask the user a question.
    QMessageBox::StandardButton exit;
    exit = QMessageBox::question(this, "Exit","Do you wish to exit?",
                                 QMessageBox::Yes | QMessageBox::No);
    if (exit = QMessageBox::Yes)
    {
        this->close();
    }
}
