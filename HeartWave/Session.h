#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include <tuple>
#include <BreathPacer.h>
#include <QString>
/*
Class: Session
Purpose: Has all the necessary key values for a session (including id for session), and the algorithms in order to compute these key values

Variables:
    int id;                                                                                 -> ID of Session
    double coherenceScore;                                                                  -> Current CS
    int heartrate;                                                                          -> Current HR
    int heartCoherence;                                                                     -> Current HC
    int challengeLevel;                                                                     -> Current CL
    double achievementScore;                                                                   -> Current AS
    int HRV;                                                                                -> Current HRV Value (low, med high)
    int length;                                                                             -> Current Session Length
    int low_count;                                                                          -> Low Score Count
    int med_count;                                                                          -> Med Score Count
    int high_count;                                                                         -> High Score Count
    std::vector<std::pair<double, double>> cs_data;                                         -> CS Mock Data
    std::vector<std::pair<double, double>> hrv_data;                                        -> HR Mock Data
    BreathPacer* breathpacer;                                                               -> BreathPacer Object

Functions:
    Session()                                                                               -> Constructor for the Session class
    void calculateCS()                                                                      -> Calculates the coherence score
    void calculateHC()                                                                      -> Calculates the heart coherence
    void calculateCL()                                                                      -> Calculates the challenge level
    void calculateAS()                                                                      -> Calculates the achievement score
    void calculateHRV()                                                                     -> Calculates the HRV
    int getID()                                                                             -> Returns the id of the session
    int getCS()                                                                             -> Returns the coherence score
    int getHC()                                                                             -> Returns the heart coherence
    int getCL()                                                                             -> Returns the challenge level
    int getHRV()                                                                            -> Returns the HRV
    int getLength()                                                                         -> Returns the length of the session
    void setChallengeLevel(int)                                                             -> Sets the challenge level
    std::tuple<int,int,int, double,int,int,double,int,int,int,int,int> display_data(int);   -> Returns Data for UI Display
    int getDataSetLength();                                                                 -> Returns Data Set Length
    void summary();                                                                         -> Prints Summary to Console
    std::tuple<double,double,double,double,int,int,double> getSummary();                    -> Returns Summary as Tuple
    std::vector<std::pair<double, double>> getCSData();                                     -> Returns Coherence Score Data
    std::vector<std::pair<double, double>> getHRVData();                                    -> Returns HRV Data
*/
class Session
{
    public:
        Session(int, std::vector<std::pair<double, double>>, std::vector<std::pair<double, double>>, int);
        void calculateCS(std::vector<std::pair<double, double>>);
        int calculateHC(double);
        void calculateCL();
        double calculateHRV(std::vector<std::pair<double, double>>);
        void calculateAS();
        int getID();
        int getCS();
        int getHC();
        int getCL();
        int getHRV();
        int getLength();
        int getCSDataSize();
        void setChallengeLevel(int);
        BreathPacer* breathpacer;
        std::tuple<int,int,int, double,int,int,double,int,int,int,int,int> display_data(int);
        int getDataSetLength();
        void summary();
        std::tuple<double,double,double,double,int,int,double> getSummary();
        std::vector<std::pair<double, double>> getCSData();
        std::vector<std::pair<double, double>> getHRVData();
        QString getDate();
        void setDate(QString newVal);
    private:
        int id;
        double coherenceScore;
        int heartrate;
        int heartCoherence;
        int challengeLevel;
        double achievementScore;
        int HRV;
        int length;
        int low_count;
        int med_count;
        int high_count;
        std::vector<std::pair<double, double>> cs_data;
        std::vector<std::pair<double, double>> hrv_data;
        QString date;

};
#endif
