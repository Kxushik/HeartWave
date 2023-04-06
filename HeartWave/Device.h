#ifndef DEVICE_H
#define DEVICE_H
#include <Session.h>
#include <History.h>
#include <Settings.h>
#include <QDebug>
#include <utility>
#include <vector>
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
        void initSession(int);
        Session* getCurrentSession();
        void endSession();
        std::tuple <int,int,int>  getSettings();
        History* getHistory();
        void initializeMockData();

    private:
        int coherence;
        int challenge;
        int nextID;
        std::vector<std::pair<double, double>> data_set1;
        std::vector<std::pair<double, double>> data_set2;
        std::vector<std::pair<double, double>> date_set3;
        Session *currentSession;
        History *dev_history;
        Settings *dev_settings;
};
#endif
