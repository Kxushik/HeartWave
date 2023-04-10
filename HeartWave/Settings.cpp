#include <Settings.h>
#include <tuple>


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

void Settings::factoryReset(){
    //Clear History, and Settings
    challengeLevel = 1;
    //Might now need this idk? Mainwindow can call some shit
}

std::tuple<int,int,int> Settings::getSettings(){
    std::tuple <int,int,int> settings = std::make_tuple(timeInterval,breaths,challengeLevel);
    return settings;
}

int Settings::getCL() {
   return challengeLevel;
}


