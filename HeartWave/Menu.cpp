#include <Menu.h>


Menu::Menu(){
    device = new Device();
    screen = new Screen();
    menuList = QStringList{ "New Session", "End Session", "Challenge Level", "Breath Pacer Interval", "Show History", "Delete Session", "Delete All Sessions", "Factory Reset" };
}

void Menu::newSession(int dataset){
    //Check which dataset to be loaded. And pass it through to device
    device->initSession(dataset);
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
