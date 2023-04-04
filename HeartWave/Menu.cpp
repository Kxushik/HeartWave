#include <Menu.h>


Menu::Menu(){
    device = new Device();
    screen = new Screen();
}

void Menu::display(){
    //
}

void Menu::newSession(){
    device->initSession();
}

void Menu::endSession(){
    device->endSession();
}

void Menu::showHistory(){
    device->getHistory()->showHistory();
}

void Menu::deleteHistory(int id){
    device->getHistory()->removeSession(id);
}

void Menu::deleteAllHistory(){
    device->getHistory()->clearSessions();
}
