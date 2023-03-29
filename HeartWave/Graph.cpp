#include <Graph.h>

Graph::Graph(){
    heartRate = 0;
    time = 0;
}

int Graph::getHR(){return heartRate;}
int Graph::getTime(){return time;}

void Graph::setHR(int newHeartRate){heartRate = newHeartRate;}
void Graph::setTime(int newTime){time = newTime;}
