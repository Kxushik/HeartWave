#include <Device.h>
#include <tuple>
Device::Device(){
    coherence = -1;
    challenge = -1;
    nextID = 0;
    battery = 100.00;
    dev_history = new History();
    dev_settings  = new Settings();
    initSession(1);
    initializeMockData();
}

void Device::initSession(int dataset){
    qDebug()<<qPrintable("Loading Dataset "+QString::number(dataset));
    std::vector<std::pair<double, double>> cs_data_set;
    std::vector<std::pair<double, double>> hrv_data_set;
    if (dataset == 1) {
          cs_data_set = cs_data_set1;
          hrv_data_set = hrv_data_set1;
    }
    if (dataset == 2) {
        cs_data_set = cs_data_set2;
        hrv_data_set = hrv_data_set2;
    }
    if (dataset == 3) {
        cs_data_set = cs_data_set3;
        hrv_data_set = hrv_data_set3;
    }

<<<<<<< HEAD
    currentSession = new Session(nextID, cs_data_set, hrv_data_set, dev_settings->getCL());
=======

    currentSession = new Session(nextID, cs_data_set, hrv_data_set);
>>>>>>> 671af192594e6809355e2cf68bfe9a52b1ce04c6
    nextID += 1;
}

Session* Device::getCurrentSession() {
    return currentSession;
}
void Device::endSession(){
    qDebug() << qPrintable("Ending Current Session ID " + QString::number(currentSession->getID()));
    currentSession->summary();
    dev_history->addSession(currentSession);
}

History* Device::getHistory(){
    return dev_history;
}

Settings* Device::getSettings(){return dev_settings;}

void Device::initializeMockData(){
    cs_data_set1= {
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
    cs_data_set2 = {
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
    cs_data_set3 ={
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
    hrv_data_set1 = {
                {118, 74},
                {119, 71},
                {121, 78},
                {122, 80},
                {124, 80},
                {124, 81},
                {127, 76},
                {129, 70},
                {129, 73},
                {130, 73},
                {131, 76},
                {132, 71},
                {132, 72},
                {134, 71},
                {136, 77},
                {136, 76},
                {139, 87},
                {139, 84},
                {140, 84},
                {143, 72},
                {145, 72},
                {147, 71},
                {149, 79},
                {150, 78},
                {151, 80},
                {152, 81},
                {153, 82},
                {154, 79},
                {155, 76},
                {157, 74},
                {158, 72},
                {160, 73},
                {161, 71},
                {162, 75},
                {162, 77},
                {163, 82},
                {166, 93},
                {169, 73}
    };
    hrv_data_set2 = {
                {0, 61},
                {3, 59},
                {12, 58},
                {21, 55},
                {27, 55},
                {30, 54},
                {38, 55},
                {43, 54},
                {46, 56},
                {51, 53},
                {54, 62},
                {61, 56},
                {64, 57},
                {74, 54},
                {80, 55},
                {95, 61},
                {99, 60},
                {102, 61},
                {109, 58},
                {113, 59},
                {122, 54},
                {125, 54},
                {130, 54},
                {133, 55},
                {139, 55},
                {145, 56},
                {153, 54},
                {160, 55},
                {165, 54},
                {169, 55},
                {177, 54},
                {180, 55}
    };
    hrv_data_set3 = {
                {0, 115},
                {7, 99},
                {14, 94},
                {17, 95},
                {21, 93},
                {32, 88},
                {45, 88},
                {49, 87},
                {55, 92},
                {61, 92},
                {72, 83},
                {76, 85},
                {80, 88},
                {85, 89},
                {89, 91},
                {93, 92},
                {107, 81},
                {112, 80},
                {118, 85},
                {127, 91},
                {133, 90},
                {138, 88},
                {141, 90},
                {145, 90},
                {155, 95},
                {160, 94},
                {169, 85},
                {174, 82},
                {178, 83},
                {180, 83}
    };
    //for (auto const& pair : data_set1) {
    //        qDebug() << qPrintable("Time: " + QString::number(pair.first) + ", Coherence Score: " + QString::number(pair.second));
    //    }
}

//Battery Functions
void Device::depleteBattery() {if (battery > 0) {battery -= 1; }}
void Device::chargeBattery() { battery = 100.00; }
double Device::getBattery() { return battery; }

void Device::setCurrentSession(Session *session) {
    currentSession = session;
}





