#include <Settings.h>


Settings::Settings(){
    timeInterval = 0;
    breaths = 0;
    challengeLevel = 1;
}

void Settings::adjustBreathPacer(int TI,int br){
    timeInterval = TI;
    breaths = br;
}

void Settings::adjustChallenge(int chal){
    challengeLevel = chal;
}

void Settings::charge(){
    //Confusion
}

void factoryReset(){
    //Clear History, and Settings
    timeInterval = 0;
    breaths = 0;
    challengeLevel = 1;
    //Might now need this idk? Mainwindow can call some shit
}

tuple<int,int,int> Settings::getSettings(){
    std::tuple <int,int,int> settings = make_tuple(timeInterval,breaths,challengeLevel);
    return settings;
}


