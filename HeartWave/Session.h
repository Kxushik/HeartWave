#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include <tuple>
#include <BreathPacer.h>
#include <Graph.h>
/*
Class: Session
Purpose: Has all the necessary key values for a session (including id for session), and the algorithms in order to compute these key values

Variables:
int id                      -> The id of the session
int coherenceScore          -> The coherence of the session
int heartCoherence          -> The heart coherence of the session
int challengeLevel          -> The challenge level of the session
int achievementScore        -> The acheivement score of the session
int HRV                     -> The HRV of the session
int length                  -> The length of the session

Functions:
Session()                   -> Constructor for the Session class
void calculateCS()          -> Calculates the coherence score
void calculateHC()          -> Calculates the heart coherence
void calculateCL()          -> Calculates the challenge level
void calculateAS()          -> Calculates the achievement score
void calculateHRV()         -> Calculates the HRV
int getID()                 -> Returns the id of the session
int getCS()                 -> Returns the coherence score
int getHC()                 -> Returns the heart coherence  
int getCL()                 -> Returns the challenge level
int getHRV()                -> Returns the HRV
int getLength()             -> Returns the length of the session
void setChallengeLevel(int) -> Sets the challenge level
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
        Graph* graph;
        BreathPacer* breathpacer;
        std::tuple<int,int,int, double,int,int,double,int,int,int,int,int> display_data(int);
        int getDataSetLength();
        void summary();
        std::tuple<double,double,double,double> getSummary();
    private:
        int id;
        double coherenceScore;
        int heartrate;
        int heartCoherence;
        int challengeLevel;
        int achievementScore;
        int HRV;
        int length;
        int low_count;
        int med_count;
        int high_count;
        std::vector<std::pair<double, double>> cs_data;
        std::vector<std::pair<double, double>> hrv_data;

};
#endif
