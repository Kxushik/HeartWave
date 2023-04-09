#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

//Global variables - Test
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    consoleMenu();
    initialize();

    connect(this, &MainWindow::updateUI, this, &MainWindow::onUpdateUI);

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

    qDebug() << qPrintable("======Initializing session values======");

    //Ask how to fill in the constructor cuz this creates two new objects
//    Menu test;
//    int timer = 0;

//    int batteryLevel = test.screen->getBattery();
//    bool batteryCharge = test.screen->getCharge();
//    bool contact = test.screen->getContact();
//    int length = test.device->getCurrentSession()->getLength();

//    int sessionId = test.device->getCurrentSession()->getID();
//    int HC = test.device->getCurrentSession()->getHC();
//    int CS = test.device->getCurrentSession()->getCS();
//    int CL = test.device->getCurrentSession()->getCL();
//    int HRV = test.device->getCurrentSession()->getHRV();

//    ui->progressBatteryLevel->setValue(batteryLevel);
//    ui->textCoherence->setText(QString::number(HC));
//    ui->textLength->setText(QString::number(timer));
//    ui->textAchievement->setText(QString::number(HRV));

    //Breath pacer initialization
    progressBar = ui->breathIndicator;
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);
    progressValue = 0;

    //Can be whatever the setting is
    int durationInSeconds = test.device->getCurrentSession()->breathpacer->getTI();
    //Duration in milliseconds divided by the number of steps (100)
    int breathTimerInterval = (durationInSeconds * 1000) / 100;
    int uiTimerInterval = 5000;
    breathTimer = new QTimer(this);
    uiTimer = new QTimer(this);
    connect(breathTimer, &QTimer::timeout, this, &MainWindow::updateBreathPacer);
    connect(uiTimer, &QTimer::timeout, this, &MainWindow::performIteration);
    breathTimer->start(breathTimerInterval);
    uiTimer->start(uiTimerInterval);
}

//Function to test the menu through the console until front-enders connect the UI to our functions...
void MainWindow::consoleMenu() {
    //Initializing a test menu (print statements to console to check values while adding the functions)

//    qDebug() << qPrintable("======Printing Screen======");
//    qDebug() << qPrintable("Battery Level: " + QString::number(test.screen->getBattery()));
//    qDebug() << qPrintable("Charge: " + QString::number(test.screen->getCharge()));
//    qDebug() << qPrintable("Contact: " + QString::number(test.screen->getContact()));
//    qDebug() << qPrintable("Length: " + QString::number(test.device->getCurrentSession()->getLength()));
//    qDebug() << qPrintable("======Printing Device======");
//    qDebug() << qPrintable("Session ID: " + QString::number(test.device->getCurrentSession()->getID()));
//    qDebug() << qPrintable("======Printing Session Variables======");
//    qDebug() << qPrintable("Achievement Score: ");
//    qDebug() << qPrintable("Heart Coherence: " + QString::number(test.device->getCurrentSession()->getHC()));
//    qDebug() << qPrintable("Coherence Score: " + QString::number(test.device->getCurrentSession()->getCS()));
//    qDebug() << qPrintable("Challenge Level: " + QString::number(test.device->getCurrentSession()->getCL()));
//    qDebug() << qPrintable("Heart Rate Variability: " + QString::number(test.device->getCurrentSession()->getHRV()));

//    //Settings test, keep so we can see how we can unpack tuples, get<i>test.device->getSettings() also works

    //testing HRV calc
    test.newSession(1);

}
void MainWindow::handleButtons() {
    //Get button
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    QString buttonName = buttonSender->objectName();

    switch(mapStringValues[buttonName.toStdString()]) {
        case stringValue::up:
            qDebug() << qPrintable("Up function");
        break;
        case stringValue::down:
            qDebug() << qPrintable("Down function");
        break;
        case stringValue::left:
            qDebug() << qPrintable("Left function");
        break;
        case stringValue::right:
            qDebug() << qPrintable("Right function");
        break;
        case stringValue::ok:
            qDebug() << qPrintable("Ok function");
        break;
        case stringValue::charge:
            qDebug() << qPrintable("Charge function");
        break;
        case stringValue::heart:
            qDebug() << qPrintable("Heart function");
        break;
        case stringValue::menu:
            qDebug() << qPrintable("Menu function");
        break;
        case stringValue::power:
            qDebug() << qPrintable("Power function");
        break;
        case stringValue::back:
            qDebug() << qPrintable("Back function");
        break;
    }

}

void MainWindow::setBattery_UI(int newVal) {
    ui->progressBatteryLevel->setValue(newVal);
}

void MainWindow::setLength_UI(int newVal) {
    ui->textLength->setText(QString::number(newVal));
}

void MainWindow::onUpdateUI(int csIndex) {
    // This function will take in a data tuple that contains all the data to be updated on the UI
    //coherence score, heart rate, achievement, etc
    std::tuple<int,int,double,int> dataTup = make_tuple(1, 2, 3.0, 4);
    int cs, hr, ac, et;
    std::tie(cs, hr, ac, et) = dataTup;

    int val = getHCVal();
    qDebug() << qPrintable("HCVal = " + QString::number(val));

    //Heart Coherence scores
    switch (val) {
    case 0:
        setLow_UI(true);
        setMed_UI(false);
        setHigh_UI(false);
        ui->textCoherence->setText(QString::fromStdString("Low"));
        break;
    case 1:
        setLow_UI(false);
        setMed_UI(true);
        setHigh_UI(false);
        ui->textCoherence->setText(QString::fromStdString("Med"));
        break;
    case 2:
        setLow_UI(false);
        setMed_UI(false);
        setHigh_UI(true);
        ui->textCoherence->setText(QString::fromStdString("High"));
        break;
    }

}

void MainWindow::performIteration() {
    std::tuple<int, double,int,int,double,int,int> dataTuple = test.device->getCurrentSession()->display_data(csIndex);
    //setHCVal(test.device->getCurrentSession()->display_data(csIndex));
    int id;
    double cs;
    int hc;
    int cl;
    double as;
    int l;
    int bti;

    std::tie(id,cs,hc,cl,as,l,bti) = data_tuple;

    setHCVal(hc);
    qDebug() << qPrintable("id: "+QString::number(id));
    qDebug() << qPrintable("CS: "+QString::number(cs));
    qDebug() << qPrintable("hc: "+QString::number(hc));
    qDebug() << qPrintable("cl: "+QString::number(cl));
    qDebug() << qPrintable("as: "+QString::number(as));
    qDebug() << qPrintable("l: "+QString::number(l));
    qDebug() << qPrintable("bti: "+QString::number(bti));
    emit updateUI(csIndex);
    csIndex++;
}

void MainWindow::setLow_UI(bool newVal) {
    if (newVal) {
        ui->buttonCoherenceLow->setStyleSheet(
            "background-color:rgb(255,0,0);"
            "color:rgb(255,255,255);"
        );
    } else {
        ui->buttonCoherenceLow->setStyleSheet(
            "background-color:rgb(25,0,0);"
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
            "background-color:rgb(0,0,25);"
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
            "background-color:rgb(0,25,0);"
            "color:rgb(255,255,255);"
        );
    }
}

void MainWindow::setHCVal(int newVal) {
    hcVal = newVal;
}

int MainWindow::getHCVal() {
    return hcVal;
}

void MainWindow::updateBreathPacer()
{
    switch (breathVal) {
    case true:
        progressValue += 1;
        break;
    case false:
        progressValue -= 1;
        break;
    }
    progressBar->setValue(progressValue);
    if (progressValue >= 100) {
        breathVal = false;
    } else if (progressValue <= 0) {
        breathVal = true;
    }
}
