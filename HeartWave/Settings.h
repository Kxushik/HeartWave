#ifndef SETTINGS_H
#define SETTINGS_H
#include <tuple>
/*
Class: Settings
Purpose: Contains functions for the user to select when in the settings menu

Variables:
    int timeInterval;                       -> Time Interval (s)
    int breaths;                            -> Num Breaths
    int challengeLevel;                     -> Challenge Level
Functions:
    Settings()                              -> Constructor for the Settings class
    void adjustBreathPacer(int, int)        -> Adjusts the breath pacer
    void adjustChallenge(int)               -> Adjusts the challenge
    void factoryReset()                     -> Resets the device to factory settings
    std::tuple <int,int,int> getSettings(); -> Return Settings Value (tuples)
    int getCL();                            -> Return Challenge Level
    int getTI();                            -> Return Time Interval
*/

class Settings
{
    public:
        Settings();
        void adjustBreathPacer(int, int);
        void adjustChallenge(int);
        void factoryReset();
        std::tuple <int,int,int> getSettings();
        int getCL();
        int getTI();
    private:
        int timeInterval;
        int breaths;
        int challengeLevel;
};
#endif
