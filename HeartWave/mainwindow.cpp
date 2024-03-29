#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);


    connect(this, &MainWindow::updateUI, this, &MainWindow::onUpdateUI);
    //Directions
    connect(ui->buttonUp, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonDown, &QPushButton::clicked, this, &MainWindow::handleButtons);
//    connect(ui->buttonLeft, &QPushButton::clicked, this, &MainWindow::handleButtons);
//    connect(ui->buttonRight, &QPushButton::clicked, this, &MainWindow::handleButtons);

    //Other
    connect(ui->buttonOk, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonCharge, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonHeart, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonMenu, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonPower, &QPushButton::clicked, this, &MainWindow::handleButtons);
    connect(ui->buttonBack, &QPushButton::clicked, this, &MainWindow::handleButtons);

    //Initialize important stuff

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

    //Initialize menu
    menuUI = ui->listMenu;
    menuUI->addItems(test.menuList);
    ui->labelMenu->setText("Menu");
    menuUI->setCurrentRow(0);
    //Disable End Session on start
    QListWidgetItem *item = menuUI->item(1);
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
    //Disable menu on start
    menuUI->setVisible(true);
    initializeGraphs();
    ui->screenBlack1->setVisible(true);
    ui->screenBlack2->setVisible(true);
    ui->screenBlack3->setVisible(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize() {
    qDebug() << qPrintable("======Initializing session values======");

    //Breath pacer initialization
    progressBar = ui->breathIndicator;
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);
    progressValue = 0;
    yMax = 0;
    xMax =0;
    //Can be whatever the setting is
    int durationInSeconds = test.device->getSettings()->getTI();
    int breathTimerInterval = (durationInSeconds * 1000) / 100;

    int uiTimerInterval = 1000;
    breathTimer = new QTimer(this);
    uiTimer = new QTimer(this);
    connect(breathTimer, &QTimer::timeout, this, &MainWindow::updateBreathPacer);
    connect(uiTimer, &QTimer::timeout, this, &MainWindow::performIteration);
    breathTimer->start(breathTimerInterval);
    uiTimer->start(uiTimerInterval);
}

void MainWindow::deinitialize() {
    breathTimer->stop();
    uiTimer->stop();
}

void MainWindow::handleButtons() {
    //Get button
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    QString buttonName = buttonSender->objectName();

    switch(mapStringValues[buttonName.toStdString()]) {
        case stringValue::up:
            handleDirection(buttonName);
        break;
        case stringValue::down:
            handleDirection(buttonName);
        break;
        case stringValue::left:
        break;
        case stringValue::right:
        break;
        case stringValue::ok:
            handleOk();
        break;
        case stringValue::charge:
            test.device->chargeBattery();
            setBattery_UI(test.device->getBattery());
        break;
        case stringValue::heart:
            test.device->setHeartContact();
            if (test.device->getHeartContact()) {
                ui->buttonHeart->setStyleSheet(
                    "image: url(:/buttons/iconHeartRate.svg);"
                    "background-color:rgb(255,0,0);"
                    "border-radius: 20px;"
                );
            } else {
                ui->buttonHeart->setStyleSheet(
                    "image: url(:/buttons/iconHeartRate.svg);"
                    "background-color: #565556;"
                    "border-radius: 20px;"
                );
            }
        break;
        case stringValue::menu:
            handleMenu();
        break;
        case stringValue::power:
            qDebug() << "Power Pressed";
            test.device->setPower() ;
            qDebug() << test.device->getPower();
            if (test.device->getPower() == false) {
                ui->screenBlack1->setVisible(true);
                ui->screenBlack2->setVisible(true);
                ui->screenBlack3->setVisible(true);
                qDebug() << "Turn Off";

            }
            else if (test.device->getPower() == true) {
                ui->screenBlack1->setVisible(false);
                ui->screenBlack2->setVisible(false);
                ui->screenBlack3->setVisible(false);
                qDebug() << "Turn On";

            }
        break;
        case stringValue::back:
            handleBack();
        break;
    }

}

void MainWindow::setBattery_UI(int newVal) {
    ui->progressBatteryLevel->setValue(newVal);
}

void MainWindow::setLength_UI(int newVal) {
    ui->textLength->setText(QString::number(newVal));
}

void MainWindow::onUpdateUI(std::tuple<int, int, int, double, int, int, double, int, int, int, int, int> dataTuple) {
    // This function will take in a data tuple that contains all the data to be updated on the UI
    int id; //ID
    int ts; //TimeStamp
    int hr; //Heart Rate
    double cs; //Cohe Score
    int hc; //Heart coher
    int cl; //Challenge level
    double as; //Acheivement score
    int l; //length
    int bti; //bti

    std::tie(id, ts, hr, cs, hc, cl, as, l, bti, lcount, mcount, hcount) = dataTuple;

    //Heart Coherence
    switch (hc) {
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

    //Heart Coherence Score
    ui->textCoherence->setText(QString::number(cs));
    //Challenge Level
    ui->textChallengeLevel->setText(QString::number(cl));
    //Acheivement Score
    ui->textAchievement->setText(QString::number(as));
    //Length
    ui->textLength->setText(QString::number(l));
    addCoordinates(ts, hr, hc);
}

void MainWindow::performIteration() {
    int dataSetBound = test.device->getCurrentSession()->getDataSetLength();
    setBattery_UI(test.device->getBattery());
    if (test.device->getPower() == false) {
            qDebug() << qPrintable("Device is turned off, to resume session please turn on...");
        }
    if (test.device->getBattery() == 0.00) {
            qDebug() << qPrintable("Battery is dead, device cannot function, please recharge...");
        }
    if (test.device->getHeartContact() == false) {
        qDebug() << qPrintable("Heart sensor missing, please reconnect");
        }
    if ((test.device->getBattery() != 0) && (test.device->getHeartContact() == true && (test.device->getPower() == true))) {
        test.device->depleteBattery();
        if (index < dataSetBound){
            std::tuple<int, int, int, double, int, int, double, int, int, int, int, int> dataTuple = test.device->getCurrentSession()->display_data(index);

            emit updateUI(dataTuple);
            index++;
        }
        else{
        }
    }

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

void MainWindow::handleDirection(QString buttonName) {
    int nextIndex = 0;
    switch(mapStringValues[buttonName.toStdString()]) {
    case stringValue::up:
        nextIndex = menuUI->currentRow() - 1;
        if (nextIndex < 0) {
            nextIndex = menuUI->count() - 1;
        }
        menuUI->setCurrentRow(nextIndex);
        break;
    case stringValue::down:
        nextIndex = menuUI->currentRow() + 1;
        if (nextIndex > menuUI->count() - 1) {
            nextIndex = 0;
        }
        menuUI->setCurrentRow(nextIndex);
        break;
    }
}

void MainWindow::handleOk() {
    int index = menuUI->currentRow();
    int dataset = ui->comboDataset->currentText().toInt();
    std::string itemName = menuUI->item(index)->text().toStdString();
    std::string menuName = ui->labelMenu->text().toStdString();
    QListWidgetItem *newSession = menuUI->item(0);
    QListWidgetItem *endSession = menuUI->item(1);
    QListWidgetItem *currItem = menuUI->currentItem();
    QString timeFormat = "yyyy-MM-dd HH:mm:ss";
    QString time;
    if (itemName == "New Session" && (newSession->flags() & Qt::ItemIsSelectable)) {
        qDebug() << qPrintable("Starting session with dataset " + QString::number(dataset) + ".");
        this->index = 0;
        yMax = 0;
        xMax = 0;
        ui->widgetGraph->graph(0)->data()->clear();
        ui->widgetGraph->graph(0)->rescaleAxes(true);
        ui->widgetGraph->replot();
        if (!ui->widgetGraph->isVisible()){
            ui->widgetGraph->setVisible(true);
        }
        std::tuple<double,double,double,double,int,int,double> dataTuple = make_tuple(0,0,0,0,0,0,0);
        handleSummary(dataTuple);
        initialize();
        test.newSession(dataset);
        QDateTime currTime = QDateTime::currentDateTime();
        time = currTime.toString(timeFormat);
        test.device->getCurrentSession()->setDate(time);
        currItem->setFlags(currItem->flags() & ~Qt::ItemIsSelectable);
        endSession->setFlags(endSession->flags() | Qt::ItemIsSelectable);
    } else if (itemName == "End Session" && (endSession->flags() & Qt::ItemIsSelectable)) {
        qDebug() << qPrintable("Ending session.");
        deinitialize();
        this->index = 0;
        yMax = 0;
        xMax = 0;
        ui->widgetGraph->graph(0)->data()->clear();
        ui->widgetGraph->graph(0)->rescaleAxes();
        //ui->widgetGraph->replot();
        std::tuple<double,double,double,double,int,int,double> dataTuple = test.device->getCurrentSession()->getSummary();
        handleSummary(dataTuple);
        test.endSession();

        currItem->setFlags(currItem->flags() & ~Qt::ItemIsSelectable);
        newSession->setFlags(newSession->flags() | Qt::ItemIsSelectable);
    } else if (itemName == "Challenge Level") { //Done
        qDebug() << qPrintable("Setting Challenge Level.");
        QStringList challengeLevels = { "1", "2", "3", "4" };
        updateMenu(challengeLevels, "Challenge Levels");
    } else if (itemName == "Breath Pacer Interval") { //Done
        qDebug() << qPrintable("Setting Breath Pacer Interval.");
        QStringList breathIntervals = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
        updateMenu(breathIntervals, "Breath Pacer Interval");
    } else if (itemName == "Show History") { //Done
        qDebug() << qPrintable("Showing history.");
        QStringList history = {};
        for (Session *s : test.device->getHistory()->getSessions()){
            QString session = "Session #" + QString::number(s->getID()) + " " + s->getDate();
            history.append(session);
        }
        updateMenu(history, "Show History");
    } else if (itemName == "Delete Session") { //Done
        qDebug() << qPrintable("Showing sessions to be deleted.");
        QStringList history = {};
        for (Session *s : test.device->getHistory()->getSessions()){
            QString session = "Session #" + QString::number(s->getID()) + " " + s->getDate();
            history.append(session);
        }
        updateMenu(history, "Delete a Session");

    } else if (itemName == "Delete All Sessions" ) {
        qDebug() << qPrintable("Deleting all sessions.");
        test.device->getHistory()->clearSessions();
        handleBack();
        ui->widgetGraph->graph(0)->data()->clear();
        ui->widgetGraph->graph(0)->rescaleAxes(true);
        ui->widgetGraph->replot();
    } else if (itemName == "Factory Reset") {
        ui->widgetGraph->graph(0)->data()->clear();
        ui->widgetGraph->graph(0)->rescaleAxes(true);
        ui->widgetGraph->replot();
        ui->widgetGraph->setVisible(false);
        test.device->getSettings()->factoryReset();
        test.device->getHistory()->clearSessions();
        std::tuple<double,double,double,double,int,int,double> blankSummary = make_tuple(0,0,0,0,0,0,0);
        std::tuple<int, int, int, double, int, int, double, int, int, int, int, int> blankUI = make_tuple(0,0,0,0,0,0,0,0,0,0,0,0);
        handleSummary(blankSummary);
        onUpdateUI(blankUI);
        setLow_UI(false);
        setMed_UI(false);
        setHigh_UI(false);
    }

    //Handle submenu stuff - Challenge Level, "Breath Pacer Interval", "Show History","Delete Session", "Delete All Sessions"
    if (menuName == "Challenge Levels") { //done
        qDebug() << qPrintable("Setting Challenge Level to " + QString::fromStdString(itemName) + ".");
        test.device->getSettings()->adjustChallenge(stoi(itemName));
        handleBack();
    } else if (menuName == "Breath Pacer Interval") { //done
        qDebug() << qPrintable("Setting Breath Pacer Interval to " + QString::fromStdString(itemName) + ".");
        test.device->getSettings()->adjustBreathPacer(stoi(itemName), 0);
        handleBack();
    } else if (menuName == "Show History") { //done
        char s = itemName[9];
        QChar qs(s);
        QString session = QString(qs);
        test.device->setCurrentSession(test.device->getHistory()->loadSession(session.toInt()));
        test.device->getHistory()->showHistory();
        handleSummary(test.device->getCurrentSession()->getSummary());
        graphColor(test.device->getCurrentSession()->getHC());
        displaySessionGraph(test.device->getCurrentSession()->getHRVData());
        handleBack();
    } else if (menuName == "Delete a Session") {
        char s = itemName[9];
        QChar qs(s);
        QString session = QString(qs);
        qDebug() << qPrintable("Deleting session " + session + ".");
        test.device->getHistory()->removeSession(session.toInt());
        handleBack();
    }

}

void MainWindow::updateMenu(QStringList list, std::string title) {
    menuUI = ui->listMenu;
    menuUI->clear();
    menuUI->addItems(list);
    ui->labelMenu->setText(QString::fromStdString(title));
}

void MainWindow::handleMenu() {
    ui->listMenu->setVisible(!ui->listMenu->isVisible());
    if (ui->listMenu->isVisible()) {
        ui->labelMenu->setText("Menu");
    } else {
        ui->labelMenu->setText("Summary");
    }
    ui->listMenu->setCurrentRow(0);
}

void MainWindow::handleBack() {
    updateMenu(test.menuList, "Menu");
}

void MainWindow::handleSummary(std::tuple<double,double,double,double,int,int,double> dataTuple) {
    double lc; //Low Coherence
    double mc; //Med Coherence
    double hc; //High Coherence
    double ac; //Average Coherence
    int cl; //Challenge Level
    int l; //Length
    double as; //Acheivement Score


    std::tie(lc, mc, hc, ac, cl, l, as) = dataTuple;

    ui->labelSummaryLC->setText(QString::number(lc) + "%");
    ui->labelSummaryMC->setText(QString::number(mc) + "%");
    ui->labelSummaryHC->setText(QString::number(hc) + "%");
    ui->labelSummaryAC->setText(QString::number(ac));
    ui->labelSummaryCL->setText(QString::number(cl));
    ui->labelSummaryL->setText(QString::number(l));
    ui->labelSummaryAS->setText(QString::number(as));

}

void MainWindow::graphColor(int score){
    switch(score) {
    case 0:
        ui->widgetGraph->graph(0)->setPen(QColor(255,0,0));
        break;
    case 1:
        ui->widgetGraph->graph(0)->setPen(QColor(0,0,255));
        break;
    case 2:
        ui->widgetGraph->graph(0)->setPen(QColor(0,255,0));
        break;
    }
}



void MainWindow::addCoordinates(double x, double y, int score){
    graphColor(score);

    if (y > yMax){
        yMax = y;
        ui->widgetGraph->yAxis->setRangeUpper(yMax+10);

    }

    if (x > xMax){
        xMax = x;
        ui->widgetGraph->xAxis->setRangeUpper(xMax);

    }
    ui->widgetGraph->graph(0)->addData(x, y);
    ui->widgetGraph->graph(0)->rescaleAxes(true);
    ui->widgetGraph->replot();
}


void MainWindow::displaySessionGraph(std::vector<std::pair<double, double>> graphData){

    int historyYMax = graphData.at(0).second;

    ui->widgetGraph->graph(0)->data()->clear();
    ui->widgetGraph->xAxis->setRange(0, graphData.back().first);

    for (int i = 0; i < graphData.size(); i++){
        ui->widgetGraph->graph(0)->addData(graphData.at(i).first, graphData.at(i).second);
        if (graphData.at(i).second > historyYMax){
            historyYMax = graphData.at(i).second;
            ui->widgetGraph->yAxis->setRangeUpper(historyYMax+10);

        }
    }
    ui->widgetGraph->graph(0)->rescaleAxes(true);
    ui->widgetGraph->replot();
}

void MainWindow::initializeGraphs(){

    ui->widgetGraph->setVisible(false);
    ui->widgetGraph->addGraph();

    ui->widgetGraph->xAxis->setLabel("Time (s)");
    ui->widgetGraph->yAxis->setLabel("Heart Rate");

    ui->widgetGraph->xAxis->setLabelColor(QColor (255, 255, 255));
    ui->widgetGraph->yAxis->setLabelColor(QColor (255, 255, 255));

    ui->widgetGraph->xAxis->setTickLabelColor(QColor (255, 255, 255));
    ui->widgetGraph->yAxis->setTickLabelColor(QColor (255, 255, 255));

    ui->widgetGraph->xAxis->setTickPen(QColor (255, 255, 255));
    ui->widgetGraph->yAxis->setTickPen(QColor (255, 255, 255));

    ui->widgetGraph->xAxis->setSubTickPen(QColor (255, 255, 255));
    ui->widgetGraph->yAxis->setSubTickPen(QColor (255, 255, 255));

    ui->widgetGraph->xAxis->setBasePen(QColor (255, 255, 255));
    ui->widgetGraph->yAxis->setBasePen(QColor (255, 255, 255));

    ui->widgetGraph->setBackground(QColor(0, 23, 45));
}
