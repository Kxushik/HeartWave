#include <Device.h>
#include <tuple>
Device::Device(){
    coherence = -1;
    challenge = -1;
    nextID = 0;
    initSession(1);
    dev_history = new History();
    dev_settings  = new Settings();
    initializeMockData();

}

void Device::initSession(int dataset){
    qDebug()<<qPrintable("Loading Dataset "+QString::number(dataset));
    nextID += 1;
    currentSession = new Session(nextID);
}

Session* Device::getCurrentSession() {
    return currentSession;
}
void Device::endSession(){
    qDebug() << qPrintable("Ending Current Session ID " + QString::number(currentSession->getID()));
    dev_history->addSession(currentSession);
}

History* Device::getHistory(){
    return dev_history;
}

std::tuple <int,int,int> Device::getSettings(){return dev_settings->getSettings();}

void Device::initializeMockData(){
    data_set1= {
            {28.10, 0.93},
            {32.60, 1.07},
            {39.12, 1.81},
            {43.62, 2.68},
            {47.81, 2.53},
            {55.89, 0.77},
            {63.65, 0.85},
            {67.68, 0.52},
            {71.72, 0.72},
            {75.29, 0.55},
            {79.79, 0.51},
            {83.52, 0.15},
            {87.55, 1.09},
            {91.75, 0.92},
            {95.47, 1.10},
            {99.66, 2.27},
            {111.00, 1.91},
            {119.69, 1.89},
            {123.57, 2.03},
            {127.14, 2.00},
            {131.64, 1.79},
            {139.40, 0.68}
    };
    data_set2 = {
            {0.37, 1.55},
            {5.49, 0.58},
            {10.44, 0.65},
            {15.56, 0.41},
            {20.14, 1.18},
            {33.88, 1.58},
            {43.58, 1.51},
            {49.26, 1.50},
            {55.85, 1.34},
            {65.01, 1.32},
            {70.32, 1.22},
            {75.44, 0.92},
            {85.33, 1.11},
            {90.09, 3.20},
            {95.58, 2.16},
            {100.35, 1.86},
            {105.47, 1.81},
            {110.60, 1.37},
            {120.49, 2.30},
            {125.43, 2.28},
            {135.87, 1.65},
            {139.90, 0.81},
            {143.93, 0.65},
            {150.70, 0.62},
            {159.31, 1.31},
            {167.18, 1.67},
            {175.61, 1.67}
    };
    date_set3 ={
            {0, 0.72},
            {4.32, 0.79},
            {13.87, 1.41},
            {18.92, 2.38},
            {24.32, 2.43},
            {28.47, 2.30},
            {34.59, 2.64},
            {39.28, 2.63},
            {44.68, 1.08},
            {49.91, 2.24},
            {60.36, 3.09},
            {64.50, 3.78},
            {75.86, 3.40},
            {89.55, 1.40},
            {99.10, 2.15},
            {104.50, 1.59},
            {109.91, 1.76},
            {119.46, 1.62},
            {129.55, 2.94},
            {134.23, 1.54},
            {141.80, 0.97},
            {143.42, 0.67},
            {149.37, 0.46},
            {159.28, 0.59},
            {164.32, 0.54},
            {172.97, 0.60},
            {179.64, 0.44}
    };
    //for (auto const& pair : data_set1) {
    //        qDebug() << qPrintable("Time: " + QString::number(pair.first) + ", Coherence Score: " + QString::number(pair.second));
    //    }
}



