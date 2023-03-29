#ifndef BREATHPACER_H
#define BREATHPACER_H
/*
Class: BreathPacer
Purpose: Contains data in order to display the graph

Variables:
int timeInterval    -> The time interval of the current session
int breaths         -> The breaths of the current session

Functions:
int getTI()         -> Returns the time interval
int getBreaths()    -> Returns the breaths
void setTI(int)     -> Sets the time interval
void setBreaths(int)-> Sets the breaths
*/

class BreathPacer
{
    public:
        BreathPacer();
        int getTI();
        int getBreaths();
        void setTI(int);
        void setBreaths(int);
};
#endif