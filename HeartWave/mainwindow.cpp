#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

//Global variables


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    consoleMenu();
    initialize();
    ui->setupUi(this);

    //Directions
    connect(ui->buttonUp, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonDown, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonLeft, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonRight, &QPushButton::clicked, this, &MainWindow::handleButtons);

    //Other
    connect(ui->buttonOk, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonCharge, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonHeart, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonMenu, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonPower, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonBack, &QPushButton::clicked, this, &MainWindow::handleButtons);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize() {
    qDebug() << qPrintable("======Initializing Button Mapping======");

    mapStringValues["buttonUp"] = stringValue::up;
    mapStringValues["buttonDown"] = stringValue::down;
    mapStringValues["buttonLeft"] = stringValue::left;
    mapStringValues["buttonRight"] = stringValue::right;
    mapStringValues["buttonOk"] = stringValue::ok;
    mapStringValues["buttonCharge"] = stringValue::charge;
    mapStringValues["buttonHeart"] = stringValue::heart;
    mapStringValues["buttonMenu"] = stringValue::menu;
    mapStringValues["buttonPower"] = stringValue::power;
    mapStringValues["buttonBack"] = stringValue::back;

    qDebug() << qPrintable("mapStringValues contains " + QString::number(mapStringValues.size()) + " entries.");

    qDebug() << qPrintable("======Initializing Value Mapping======");

}

//Function to test the menu through the console until front-enders connect the UI to our functions...
void MainWindow::consoleMenu() {
    //Initializing a test menu (print statements to console to check values while adding the functions)
    Menu test;
    qDebug() << qPrintable("======Printing Screen======");
    qDebug() << qPrintable("Battery Level: " + QString::number(test.screen->getBattery()));
    qDebug() << qPrintable("Charge: " + QString::number(test.screen->getCharge()));
    qDebug() << qPrintable("Contact: " + QString::number(test.screen->getContact()));
    qDebug() << qPrintable("Length: " + QString::number(test.device->getCurrentSession()->getLength()));
    qDebug() << qPrintable("======Printing Device======");
    qDebug() << qPrintable("Session ID: " + QString::number(test.device->getCurrentSession()->getID()));
    qDebug() << qPrintable("======Printing Session Variables======");
    qDebug() << qPrintable("Achievement Score: ");
    qDebug() << qPrintable("Heart Coherence: " + QString::number(test.device->getCurrentSession()->getHC()));
    qDebug() << qPrintable("Coherence Score: " + QString::number(test.device->getCurrentSession()->getCS()));
    qDebug() << qPrintable("Challenge Level: " + QString::number(test.device->getCurrentSession()->getCL()));
    qDebug() << qPrintable("Heart Rate Variability: " + QString::number(test.device->getCurrentSession()->getHRV()));

    //Settings test, keep so we can see how we can unpack tuples, get<i>test.device->getSettings() also works
    int ti,br,cl;
    std::tie(ti,br,cl) = test.device->getSettings();
    qDebug() << qPrintable("Tuple TI " + QString::number(ti));
    qDebug() << qPrintable("Tuple Br " + QString::number(br));
    qDebug() << qPrintable("Tuple CL " + QString::number(cl));
}

void MainWindow::handleButtons() {
    //Get button
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    QString buttonName = buttonSender->objectName();

    switch(mapStringValues[buttonName.toStdString()]) {
        case stringValue::up:
            qDebug() << qPrintable("Up function");
//            setBattery(69);
//            ui->buttonCoherenceLow->setChecked(true);
            setLow_UI(true);
        break;
        case stringValue::down:
            qDebug() << qPrintable("Down function");
            setMed_UI(true);
        break;
        case stringValue::left:
            qDebug() << qPrintable("Left function");
            setHigh_UI(true);
        break;
        case stringValue::right:
            qDebug() << qPrintable("Right function");
            setHigh_UI(false);
        break;
        case stringValue::ok:
            qDebug() << qPrintable("Ok function");
        break;
        case stringValue::charge:
            qDebug() << qPrintable("Charge funtion");
        break;
        case stringValue::heart:
            qDebug() << qPrintable("Heart funtion");
        break;
        case stringValue::menu:
            qDebug() << qPrintable("Menu funtion");
        break;
        case stringValue::power:
            qDebug() << qPrintable("Power funtion");
        break;
        case stringValue::back:
            qDebug() << qPrintable("Back funtion");
        break;
    }

}

void MainWindow::setBattery_UI(int newVal) {
    ui->progressBatteryLevel->setValue(newVal);
}

//void MainWindow::setCharge_UI(int newVal) {
//    ui->
//}

//void MainWindow::setContact_UI(bool newVal) {
//    ui->
//}

void MainWindow::setLength_UI(int newVal) {
    ui->textLength->setText(QString::number(newVal));
}

void MainWindow::setHC_UI(int newVal) {
    ui->textCoherence->setText(QString::number(newVal));
}

void MainWindow::setLow_UI(bool newVal) {
    if (newVal) {
        ui->buttonCoherenceLow->setStyleSheet(
            "background-color:rgb(255,0,0);"
            "color:rgb(255,255,255);"
        );
    } else {
        ui->buttonCoherenceLow->setStyleSheet(
            "background-color:rgb(125,0,0);"
            "color:rgb(255,255,255);"
        );
    }
}

void MainWindow::setMed_UI(bool newVal) {
    if (newVal) {
        ui->buttonCoherenceMedium->setStyleSheet(
            "background-color:rgb(0,0,255);"
            "color:rgb(255,255,255);"
        );
    } else {
        ui->buttonCoherenceMedium->setStyleSheet(
            "background-color:rgb(0,0,125);"
            "color:rgb(255,255,255);"
        );
    }
}

void MainWindow::setHigh_UI(bool newVal) {
    if (newVal) {
        ui->buttonCoherenceHigh->setStyleSheet(
            "background-color:rgb(0,255,0);"
            "color:rgb(255,255,255);"
        );
    } else {
        ui->buttonCoherenceHigh->setStyleSheet(
            "background-color:rgb(0,125,0);"
            "color:rgb(255,255,255);"
        );
    }
}

