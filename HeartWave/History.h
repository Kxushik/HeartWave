#ifndef HISTORY_H
#define HISTORY_H
#include <Session.h>
#include <vector>
/*
Class: History
Purpose: Stores all previous sessions in a vector with session objects, also contains functions to add/remove accordingly

Variables:
vector<Session> sessions  -> The history of all previous sessions

Functions:
History()                  -> Constructor for the History class
void removeSession(int)    -> Removes a session from the history
void addSession(Session)   -> Adds a session to the history
void clearSessions()       -> Clears all sessions from the history
Session loadSession(int)   -> Loads a session from the history
void getSessions()         -> Returns the history
*/
class History
{
    public:
        History();
        void removeSession(int);
        void addSession(Session*);
        void clearSessions();
        Session* loadSession(int);
        std::vector<Session*> getSessions();
    private:
        std::vector<Session*> sessions;
};
#endif
