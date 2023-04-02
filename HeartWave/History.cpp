#include <History.h>

History::History(){

}

void History::removeSession(int id){
    for (int i = 0; i< sessions.size(); i++){
        if (sessions[i]->getID() == id){
            sessions.erase(sessions.begin()+i);
        }
    }
}

void History::addSession(Session *newSession){ sessions.push_back(newSession); }

void History::clearSessions(){sessions.clear();}

Session* History::loadSession(int id){ return sessions[id]; }

std::vector<Session*> History::getSessions(){ return sessions; }
