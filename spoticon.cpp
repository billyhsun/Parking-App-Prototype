#include "spoticon.h"           //Including class declaration
#include <QMessageBox>          //Class for any dialog boxes to give the user information/to ask a question.
#include <QtCore>               //Core module
#include <QtGui>
#include <QDebug>               //Class that allows for output; for testing purposes.
#include <QGraphicsItem>        //Base class for all graphics items
#include <QPainter>             //Class for painting.
#include <QInputDialog>         //Class for a dialog that gets a single piece of information from user.
#include <Qtime>                //Time module - used for keeping track of the time of parking/time of removal.


//Defining constructor
SpotIcon::SpotIcon(QGraphicsItem *parent) :
    QGraphicsObject(parent) //Superclass constructor
{
    //Setting the inital status of the parking spot
    Pressed = false;
    Reserved = false;

    res_Window = new inputDialog();

    //Connects the spot to its input window - execute return_Variables when the user clicks 'Confirm'.
    connect(res_Window, SIGNAL(Reserved()), this, SLOT(return_Variables()));
}

//Setting the rectangular frames for the objects.
QRectF SpotIcon::boundingRect() const
{
    return QRectF(-75, -75, 75, 75);
}

void SpotIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF rec = boundingRect();
    QBrush brush (Qt:: green); //Setting a brush.

    //Case 1 - set color to green.
    if (not Pressed and not Reserved)
    {
        painter->fillRect(rec, brush);
        painter->drawRect(rec);
    }

    //Case 2 - set color to red.
    if (not Pressed and Reserved)
    {
        brush.setColor(Qt::red);
        painter->fillRect(rec, brush);
        painter->drawRect(rec);
    }

    //Case 3 - user clicks on an unreserved spot - set color to blue.
    if (Pressed and not Reserved)
    {
        brush.setColor(Qt::blue);
        painter->fillRect(rec, brush);
        painter->drawRect(rec);

        //Use a QMessageBox to ask the user if they would like to reserve the spot.
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(res_Window, "Reservation", "Do you wish to reserve this spot?",
                                            QMessageBox::Yes | QMessageBox::No);
        if (confirm == QMessageBox::Yes)
        {
            Pressed = false;
            res_Window->show(); //Show the input dialog to allow for user input.
        }
        else
        {
            Pressed = false;
        }
    }

    //Case 4 - user clicks on a reserved spot.
    if (Pressed and Reserved)
    {
        //User a QMessageBox to tell the user that the spot is reserved.
        QMessageBox ::StandardButton reply;
        reply = QMessageBox::information(res_Window, "Reservation", "This spot is already reserved.",
                                         QMessageBox::Yes);
        if (reply == QMessageBox ::Yes)
        {
            Pressed = false;
        }
    }
}

void SpotIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);

}

void SpotIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mousePressEvent(event);
}

//Function to retrieve variables from user input in the input dialog.
void SpotIcon::return_Variables()
{
    id_Liscence = res_Window->temp_ID;
    time_parked = QTime::currentTime(); //determines time when parked.
    hr_reserved = res_Window->temp_hr;
    min_reserved = res_Window->temp_min;
    sec_reserved = hr_reserved*3600 + min_reserved*5; //min_reserved is only multiplied by 5 for testing purposes.
                                                      //In actual application, multiply by 60.
    time_due = time_parked.addSecs(sec_reserved);
    Reserved = res_Window->sstatus; //res_Window's status variable will only return true if the user clicks the 'Confirm'
                                    //button. This sets the spot's 'Reserved' status as true.
    Pressed = false;
}

//Function to determine if this spot is the one that the user wants to remove a car from.
void SpotIcon::compare_Input()
{
    if(id_Liscence == user_Input and id_Liscence != "")
    {
        Pressed = false;
        Reserved = false;
        QString text;
        QTime c_Time = QTime::currentTime();
        if(c_Time <= time_due) //If the user has left on time.
        {
            text = "You have left on time.";
        }
        else //If it is overdue.
        {
            int ct_hr = c_Time.hour();
            int ct_min = c_Time.minute() + ct_hr*60;
            int ct_sec = c_Time.second() + ct_min*60; //This variableis only created for testing purposes. In actual
                                                      //application, the fine is calculated based on minutes.
            int td_hr = time_due.hour();
            int td_min = time_due.minute() + td_hr*60;
            int td_sec = time_due.second() + td_min*60; //Same case as ct_sec.
            int t_diff = ct_sec - td_sec; //Determines how long the user has over-parked.

            int fine = t_diff/5; //determine fine - for testing, it's $1 per 5 sec, but in actual application it's $1 for
                                 //every 10 minutes.

            text = QString("You are overtime. Your fee is: $%1 .00").arg(fine);
        }
        //Tell the user if they have left on time, or if not, their fine.
        QMessageBox::StandardButtons box;
        box = QMessageBox::information(0,"Leaving", text,
                                       QMessageBox::Yes | QMessageBox::No);
    }
}

