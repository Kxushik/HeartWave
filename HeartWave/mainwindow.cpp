#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    consoleMenu();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
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
    test.endSession();
    test.newSession();
    test.endSession();
    test.showHistory();
    qDebug() << qPrintable("Tuple TI " + QString::number(ti));
    qDebug() << qPrintable("Tuple Br " + QString::number(br));
    qDebug() << qPrintable("Tuple CL " + QString::number(cl));

}
