#include <Session.h>
#include <QDebug>

Session::Session(int init_id, std::vector<std::pair<double, double>> cs_data_set, std::vector<std::pair<double, double>> hrv_data_set){
    id  = init_id;
    coherenceScore = 0;
    heartCoherence = 0;
    challengeLevel = 1;
    achievementScore = 0;
    HRV = 0;
    length = 0;
    graph = new Graph();
    breathpacer = new BreathPacer();
    cs_data = cs_data_set;
    hrv_data = hrv_data_set;

}

//OPTIONAL
void Session::calculateCS(std::vector<std::pair<double, double>> cs_data_set){
    //Measure of degree, stable pattern rhythhm resembling a sine wave at a single freq
    //between 0.04-0.24 Hz (3-15 cycles per minute).
    //Score is between 0-16
    //0.5 Basic - Good beingger Level
    //1.0 Good
    //2.0 Very Good
    //3.0+ Excellent
    if (HRV <= 0.003) {
        //ultralow (bad)
    }
    else if (HRV >= 0.0033 && HRV <= 0.004) {
       //very low
    }
    else if (HRV > 0.04 && HRV <= 0.15) {
       //low
    }
    else if (HRV > 0.15 && HRV <= 0.40) {
       //high
    }
}

//DONE
void Session::calculateHC(double cs){
    //Heart Coeherence = Internal Harmory, LEDS at top are reflective of it (64 second interval updates)
    float lbound = 0.0, ubound = 0.0;
    if (challengeLevel == 1) {
        lbound = 0.5, ubound = 0.9;
    }
    if (challengeLevel == 2) {
        lbound = 0.6,ubound = 2.1;
    }
    if (challengeLevel == 3) {
        lbound = 1.8, ubound = 4.0;
    }
    if (challengeLevel == 4) {
        lbound = 4.0, ubound = 6.0;
    }
    if (cs < lbound){
        //Low Coherence (RED COLOUR)
        qDebug() << qPrintable("Low Coherence");
        //qDebug() << qPrintable(QString::number(lbound));
        qDebug() << qPrintable(QString::number(cs));
    }
    else if (cs > ubound){
        //High Coherence (GREEN COLOUR)
        qDebug() << qPrintable("High Coherence");
        qDebug() << qPrintable(QString::number(cs));
    }
    else{
        //Normal Coherence (BLUE COLOUR)
        qDebug() << qPrintable("Normal Coherence");
        qDebug() << qPrintable(QString::number(cs));
    }
}

//DONE
void Session::calculateCL(){
    //Might be the same as HC above^
    // Medium (Lower and Higher than values indicate respective coherence levels
    // Level 1 0.5-0.9
    // Level 2 0.6-2.1
    // Level 3 1.8-4.0
    // Level 4 4.0-6.0
    float lbound = 0.0, ubound = 0.0;
    switch(challengeLevel){
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

//DONE
void Session::calculateAS(){
    //AS = Sum of the coherenceScore over the length of the session
    achievementScore += coherenceScore;
}

//idk
double Session::calculateHRV(std::vector<std::pair<double, double>> hrv_data_set){

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

void Session::runHC() {
    for (int i=0; i<cs_data.size(); i++) {
        calculateHC(std::get<1>(cs_data[i]));
    }
}
