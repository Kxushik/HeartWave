#ifndef MENU_H
#define MENU_H
#include <Device.h>
#include <Screen.h>
#include <QStringList>
/*
Class: Menu
Purpose: Provides functions for the device

Variables:

Functions:
Menu()                      -> Constructor for the Menu class
void display()              -> Displays the menu   
void newSession()           -> Starts a new session
void endSession()           -> Ends the current session
void showHistory()          -> Displays the history
void deleteHistory(int)     -> Deletes a specific history
void deleteAllHistory()     -> Deletes all history
*/

class Menu
{
public:
    Menu();
    void display();
    void newSession();
    void endSession();
    void showHistory();
    void deleteHistory(int);
    void deleteAllHistory();
    Device *device;
    Screen *screen;
    QStringList menuList;

};
#endif
