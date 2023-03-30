#include <Screen.h>

Screen::Screen(){
    battery = 100;
    charge,contact = false;

}

int Screen::getBattery(){return battery;}
bool Screen::getContact(){return contact;}
bool Screen::getCharge(){return charge;}

void Screen::setBattery(int newCharge){battery = newCharge;}

void Screen::setContact(bool newContact){contact = newContact;}

void Screen::setCharge(bool newCharge){if (newCharge){setBattery(100);}}
