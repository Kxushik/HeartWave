#include <Session.h>

Session::Session(int init_id){
    id  = init_id;
    coherenceScore = 0;
    heartCoherence = 0;
    challengeLevel = 0;
    achievementScore = 0;
    HRV = 0;
    length = 0;
    graph = new Graph();
    breathpacer = new BreathPacer();
}

void Session::calculateCS(){
    //Measure of degree, stable pattern rhythhm resembling a sine wave at a single freq
    //between 0.04-0.24 Hz (3-15 cycles per minute).
    //Score is between 0-16
    //0.5 Basic - Good beingger Level
    //1.0 Good
    //2.0 Very Good
    //3.0+ Excellent
}

void Session::calculateHC(){
    //Heart Coeherence = Internal Harmory, LEDS at top are reflective of it (64 second interval updates)
}
void Session::calculateCL(){
    //Might be the same as HC above^
}

void Session::calculateAS(){
    //AS = Sum of the coherenceScore over the length of the session
    achievementScore += coherenceScore;
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
