#include <Device.h>

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



