#include <Device.h>
#include <tuple>
Device::Device(){
    coherence = -1;
    challenge = -1;
    nextID = 0;
    power = true;
    battery = 100.00;
    heartContact = true;
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
    currentSession = new Session(nextID, cs_data_set, hrv_data_set, dev_settings->getCL());
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
                {1, 74},
                {2, 71},
                {3, 78},
                {4, 80},
                {5, 80},
                {6, 81},
                {7, 76},
                {8, 70},
                {9, 73},
                {10, 73},
                {11, 76},
                {12, 71},
                {13, 72},
                {14, 71},
                {15, 77},
                {16, 76},
                {17, 87},
                {18, 84},
                {19, 84},
                {20, 72},
                {21, 72},
                {22, 71},
                {23, 79},
                {24, 78},
                {25, 80},
                {26, 81},
                {27, 82},
                {28, 79},
                {29, 76},
                {30, 74},
                {31, 72},
                {32, 73},
                {33, 71},
                {34, 75},
                {35, 77},
                {36, 82},
                {37, 93},
                {38, 73}
    };
    hrv_data_set2 = {
                {1, 61},
                {2, 59},
                {3, 58},
                {4, 55},
                {5, 55},
                {6, 54},
                {7, 55},
                {8, 54},
                {9, 56},
                {10, 53},
                {11, 62},
                {12, 56},
                {13, 57},
                {14, 54},
                {15, 55},
                {16, 61},
                {17, 60},
                {18, 61},
                {19, 58},
                {20, 59},
                {21, 54},
                {22, 54},
                {23, 54},
                {24, 55},
                {25, 55},
                {26, 56},
                {27, 54},
                {28, 55},
                {29, 54},
                {30, 55},
                {31, 54},
                {32, 55}
    };
    hrv_data_set3 = {
                {1, 115},
                {2, 99},
                {3, 94},
                {4, 95},
                {5, 93},
                {6, 88},
                {7, 88},
                {8, 87},
                {9, 92},
                {10, 92},
                {11, 83},
                {12, 85},
                {13, 88},
                {14, 89},
                {15, 91},
                {16, 92},
                {17, 81},
                {18, 80},
                {19, 85},
                {20, 91},
                {21, 90},
                {22, 88},
                {23, 90},
                {24, 90},
                {25, 95},
                {26, 94},
                {27, 85},
                {28, 82},
                {29, 83},
                {30, 83}
    };
}

//Battery Functions
void Device::depleteBattery() {if (battery > 0) {battery -= 1; }}
void Device::chargeBattery() { battery = 100.00; }
double Device::getBattery() { return battery; }

//HeartContact Functions
void Device::setHeartContact() { if (heartContact == true) { heartContact = false; } else { heartContact = true; } }
bool Device::getHeartContact() { return heartContact; }

void Device::setCurrentSession(Session *session) {
    currentSession = session;
}


//Power Functions
void Device::setPower() { if (power == true) { power = false; } else { power = true; } }
bool Device::getPower() { return power; }



