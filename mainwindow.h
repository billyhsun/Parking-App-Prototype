#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>          //The class for the main window; the main user interface.
#include <QGraphicsScene>       //Class for the surface on which graphical items are displayed.
#include <QWidget>              //The base class for every object on the user interface.
#include <QtCore>               //Core module
#include "inputdialog.h"        //Class declaration for the input window for reservation.
#include "spoticon.h"           //Class declaration for the parking spot objects on the graphics scene.

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow //Inheriting the properties of main windows.
{
    //Q_OBJECT macro; allows for signal-slot mechanisms (the way 2 objects interact with eachother).
    Q_OBJECT

public:
    //Constructor
    explicit MainWindow(QWidget *parent = 0);

    //Destructor
    ~MainWindow();

    //Dynamic variable used for user input of driver's liscence ID when they want to remove their car.
    QString Input;

private:
    //Initializing the user interface, graphics scene, and parking slot objects.
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SpotIcon *spot_1;
    SpotIcon *spot_2;
    SpotIcon *spot_3;
    SpotIcon *spot_4;
    SpotIcon *spot_5;
    SpotIcon *spot_6;
    SpotIcon *spot_7;
    SpotIcon *spot_8;

private slots:
    //Slots - what the main window does after receiving a signal from another object.
    void check_Clicked();
    void exit_Clicked();
};

#endif // MAINWINDOW_H
