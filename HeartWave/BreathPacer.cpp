#include <BreathPacer.h>

BreathPacer::BreathPacer(){
    timeInterval = 2;
    breaths = 0;
}

int BreathPacer::getTI(){return timeInterval;}

int BreathPacer::getBreaths(){ return breaths; }

void BreathPacer::setTI(int newTimeInterval){
    if (newTimeInterval >= 1 && newTimeInterval<=30){timeInterval = newTimeInterval;}
}

void BreathPacer::setBreaths(int newBreaths){breaths = newBreaths;}
