#ifndef SCREEN_H
#define SCREEN_H

/*
Class: Screen
Purpose: Contains the data that will be displayed on the UI (screen part of example UI)

Variables:
    int battery             -> The battery level of the device
    bool contact            -> HR Contact (Actively Breathing)
    bool charge             -> Whether the device is charging

Functions:
    Screen()                -> Constructor for the Screen class
    int getBattery()        -> Returns the battery level
    bool getContact()       -> Returns the contact status
    bool getCharge()        -> Returns the charge status
    void setBattery(int)    -> Sets the battery level
    void setContact(bool)   -> Sets the contact status
    void setCharge(bool)    -> Sets the charge status
*/

class Screen
{
    public:
        Screen();
        int getBattery();
        bool getContact();
        bool getCharge();
        void setBattery(int);
        void setContact(bool);
        void setCharge(bool);
    private:
        int battery;
        bool contact;
        bool charge;
};
#endif
