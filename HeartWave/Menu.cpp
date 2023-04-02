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
    device->showHistory();
}

void Menu::deleteHistory(int id){
    device->deleteHistory(id);
}

void Menu::deleteAllHistory(){
    device->deleteAllHistory();
}
