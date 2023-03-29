#ifndef SESSION_H
#define SESSION_H
/*
Class: Session
Purpose: Has all the necessary key values for a session (including id for session), and the algorithms in order to compute these key values

Variables:
int id                      -> The id of the session
int coherenceScore          -> The coherence of the session
int heartCoherence          -> The heart coherence of the session
int challengeLevel          -> The challenge level of the session
int HRV                     -> The HRV of the session
int length                  -> The length of the session

Functions:
Session()                   -> Constructor for the Session class
void calculateCS()          -> Calculates the coherence score
void calculateHC()          -> Calculates the heart coherence
void calculateCL()          -> Calculates the challenge level
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
        Session();
        void calculateCS();
        void calculateHC();
        void calculateCL();
        void calculateHRV();
        int getID();
        int getCS();
        int getHC();
        int getCL();
        int getHRV();
        int getLength();
        void setChallengeLevel(int);
    private:
        int id;
        int coherenceScore;
        int heartCoherence;
        int challengeLevel;
        int HRV;
        int length;
};
#endif