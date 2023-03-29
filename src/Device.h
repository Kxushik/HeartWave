#ifndef DEVICE_H
#define DEVICE_H
#include <Session.h>
/*
Class: Device
Purpose: Main purpose is to initialize a session, takes data from settings 

Variables:
int coherence           -> The coherence of the current session
int challenge           -> The challenge of the current session
Session currentSession  -> The current session

Functions
Device()               -> Constructor for the Device class
void initSession()     -> Initializes a new session
*/

class Device
{
    public:
        Device();
        void initSession();
    private:
        int coherence;
        int challenge;
        Session currentSession;
};
#endif