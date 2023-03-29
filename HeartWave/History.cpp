#include <History.h>

History::History(){

}

void History::removeSession(int id){sessions.erase(id);}

void History::addSession(Session *newSession){sessions.push_back(newSession);}

void History::clearSessions(){sessions.clear();}

Session* History::loadSession(int id){return sessions[id];}

std::vector<Session*> History::getSessions(){return sessions;}
