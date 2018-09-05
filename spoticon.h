#ifndef SPOTICON_H
#define SPOTICON_H

#include <QGraphicsObject>      //The class for all graphics objects.
#include <QRectF>               //Floating rectangle class - creates rectangles/rectangular frames for graphics objects.
#include <QTime>                //Time module - used for keeping track of the time of parking/time of removal.
#include <QtCore>               //Core module
#include <QString>              //String class for Qt
#include "inputdialog.h"        //Including class declaration.

class SpotIcon : public QGraphicsObject //Inherting properties of all graphics objects.
{
    Q_OBJECT //Q_OBJECT macro - refer to mainwindow.h.

public:
    //Constructor
    SpotIcon(QGraphicsItem *parent = 0);

    //Function to create the outer rectangular frame for the spot objects.
    QRectF boundingRect() const;

    //Function to change the color of the spots depending on their status.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    //Variables for fee calculations.
    int hr_reserved, min_reserved, sec_reserved;

    //QTime objects that contain when the car was parked and when it is due.
    QTime time_parked, time_due;

    //Determines if this is the slot that the user wants to remove from.
    void compare_Input();

    //Determine the status of the spot.
    bool Pressed, Reserved;

    //id_Liscence - what the user inputs when they park the car.
    //user_Input - refer to mainwindow.cpp.
    QString id_Liscence;
    QString user_Input;

private:
    //A dialog object that pops up when the user wants to reserve a spot.
    inputDialog *res_Window;

private slots:
    //Function that is executed when the input dialog is closed.
    void return_Variables();

protected:
    //Mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SPOTICON_H
