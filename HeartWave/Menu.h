#ifndef MENU_H
#define MENU_H
#include <Device.h>
#include <Screen.h>
#include <QStringList>
#include <utility>
/*
Class: Menu
Purpose: Provides functions for the device

Variables:
    Device *device;         -> Device Object
    Screen *screen;         -> Screen Object
    QStringList menuList;   -> QStringList of Menu Options

Functions:
    Menu()                      -> Constructor for the Menu class
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
    void newSession(int);
    void endSession();
    void showHistory();
    void deleteHistory(int);
    void deleteAllHistory();
    Device *device;
    Screen *screen;
    QStringList menuList;

};
#endif
