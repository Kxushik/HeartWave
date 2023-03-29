#ifndef GRAPH_H
#define GRAPH_H
/*
Class: Graph
Purpose: Contains data in order to display the graph

Variables:
int heartRate    -> The heart rate of the current session
int time         -> The time of the current session

Functions:
int getHR()      -> Returns the heart rate
int getTime()    -> Returns the time
void setHR(int)  -> Sets the heart rate
void setTime(int)-> Sets the time
*/

class Graph
{
    public:
        Graph();
        int getHR();
        int getTime();
        void setHR(int);
        void setTime(int);
};
#endif