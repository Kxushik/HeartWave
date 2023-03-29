#ifndef SETTINGS_H
#define SETTINGS_H
#include <tuple>
/*
Class: Settings
Purpose: Contains functions for the user to select when in the settings menu

Variables:

Functions:
Settings()                          -> Constructor for the Settings class
void adjustBreathPacer(int, int)    -> Adjusts the breath pacer
void adjustChallenge(int)           -> Adjusts the challenge
void charge()                       -> Charges the device
void factoryReset()                 -> Resets the device to factory settings
*/

class Settings
{
    public:
        Settings();
        void adjustBreathPacer(int, int);
        void adjustChallenge(int);
        void charge();
        void factoryReset();
        std::tuple <int,int,int> getSettings();
    private:
        int timeInterval;
        int breaths;
        int challengeLevel;
};
#endif
