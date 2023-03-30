#include <Session.h>

Session::Session(int init_id){
    id  = init_id;
    coherenceScore = 0;
    heartCoherence = 0;
    challengeLevel = 0;
    HRV = 0;
    length = 0;
    graph = new Graph();
    breathpacer = new BreathPacer();
}

void Session::calculateCS(){
    //Calc CS
}

void Session::calculateHC(){
    //
}
void Session::calculateCL(){
    //
}

void Session::calculateHRV(){
    //
}

int Session::getID(){return id;}
int Session::getCS(){return coherenceScore;}
int Session::getHC(){return heartCoherence;}
int Session::getCL(){return challengeLevel;}
int Session::getHRV(){return HRV;}
int Session::getLength(){return length;}

void Session::setChallengeLevel(int newChallengeLevel){
    //
}
