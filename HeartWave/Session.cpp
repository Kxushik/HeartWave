#include <Session.h>
#include <QDebug>

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
    // Medium (Lower and Higher than values indicate respective coherence levels
    // Level 1 0.5-0.9
    // Level 2 0.6-2.1
    // Level 3 1.8-4.0
    // Level 4 4.0-6.0
    float lbound = 0.0, ubound = 0.0;
    switch(level){
        case 1:
            lbound = 0.5, ubound = 0.9;
        case 2:
            lbound = 0.6,ubound = 2.1;
        case 3:
            lbound = 1.8, ubound = 4.0;
        case 4:
            lbound = 4.0, ubound = 6.0;
    }
    if (coherenceScore < lbound){
        //Low Coherence
        qDebug() << qPrintable("Low Coherence");
    }
    else if (coherenceScore > ubound){
        //High Coherence
        qDebug() << qPrintable("High Coherence");
    }
    else{
        //Normal Coherence
        qDebug() << qPrintable("Normal Coherence");
    }
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
