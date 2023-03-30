#include <Device.h>

Device::Device(){
    coherence = -1;
    challenge = -1;
    initSession();
    dev_history = new History();
    dev_settings  = new Settings();
}

void Device::initSession(){
    int newID = dev_history->getSessions().size();
    currentSession = new Session(newID);
}



