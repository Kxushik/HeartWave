#include <Device.h>
#include <tuple>
Device::Device(){
    coherence = -1;
    challenge = -1;
    nextID = 0;
    initSession();
    dev_history = new History();
    dev_settings  = new Settings();
}

void Device::initSession(){
    nextID += 1;
    currentSession = new Session(nextID);
}

Session* Device::getCurrentSession() {
    return currentSession;
}
void Device::endSession(){
    qDebug() << qPrintable("Ending Current Session ID " + QString::number(currentSession->getID()));
    dev_history->addSession(currentSession);
}

void Device::showHistory(){
    qDebug() << qPrintable("======History======");
    for (Session *s :dev_history->getSessions()){
        qDebug() << qPrintable("Session # " + QString::number(s->getID()));
    }
}

void Device::deleteHistory(int id){
    dev_history->removeSession(id);
}

void Device::deleteAllHistory(){
    dev_history->clearSessions();
}

std::tuple <int,int,int> Device::getSettings(){return dev_settings->getSettings();}



