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
    int coherence;                                          -> Current Coherence Value
    int challenge;                                          -> Current Challenge Level
    int nextID;                                             -> Session ID count
    double battery;                                         -> Battery Value
    bool heartContact;                                      -> Heart Sensor connection (True = Connected, False = Disconnected)
    std::vector<std::pair<double, double>> cs_data_set1;    -> Coherence Score Mock Data
    std::vector<std::pair<double, double>> cs_data_set2;    -> Coherence Score Mock Data
    std::vector<std::pair<double, double>> cs_data_set3;    -> Coherence Score Mock Data
    std::vector<std::pair<double, double>> hrv_data_set1;   -> Heart Rate Mock Data
    std::vector<std::pair<double, double>> hrv_data_set2;   -> Heart Rate Mock Data
    std::vector<std::pair<double, double>> hrv_data_set3;   -> Heart Rate Mock Data
    Session *currentSession;                                -> Current Session Object
    History *dev_history;                                   -> History Object
    Settings *dev_settings;                                 -> Settings Object

Functions
    Device();                                               -> Device Constructor
    void initSession(int);                                  -> initialize a new session
    Session* getCurrentSession();                           -> Return current session
    void endSession();                                      -> End Current Session
    Settings* getSettings();                                -> Return Settings
    History* getHistory();                                  -> Return History
    void setCurrentSession(Session* session);               -> Load a Session
    void initializeMockData();                              -> Init Mock Data
    double getBattery();                                    -> Return Battery
    void depleteBattery();                                  -> Deplete Battery
    void chargeBattery();                                   -> Charge Battery
    bool getHeartContact();                                 -> Return heart contact value
    void setHeartContact();                                 -> Set heart contact value
*/

class Device
{
    public:
        Device();
        void initSession(int);
        Session* getCurrentSession();
        void endSession();
        Settings* getSettings();
        History* getHistory();
        void setCurrentSession(Session* session);
        void initializeMockData();
        double getBattery();
        void depleteBattery();
        void chargeBattery();
        bool getHeartContact();
        void setHeartContact();
        void setPower();
        bool getPower();

    private:
        int coherence;
        int challenge;
        bool power;
        int nextID;
        double battery;
        bool heartContact;
        std::vector<std::pair<double, double>> cs_data_set1;
        std::vector<std::pair<double, double>> cs_data_set2;
        std::vector<std::pair<double, double>> cs_data_set3;
        std::vector<std::pair<double, double>> hrv_data_set1;
        std::vector<std::pair<double, double>> hrv_data_set2;
        std::vector<std::pair<double, double>> hrv_data_set3;
        Session *currentSession;
        History *dev_history;
        Settings *dev_settings;
};
#endif
