//-----------------------------------------------------------------------
//Program: ParkSmart application - midterm project
//Purpose: To solve a real world problem that deals with difficulty in
//         finding parking - refer to Software Architecture Document.
//Creator: Vicky Zhang, Bill Sun, James Jin
//For: Mr. Noukhovitch
//Section: ICS4U1 - 02
//Date Completed: Jan. 21, 2015
//-----------------------------------------------------------------------

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //Creating the main window.
    w.show();

    return a.exec();
}
