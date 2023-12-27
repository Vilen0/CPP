#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "TrainCar.h"
#include <stack>
#include <string>
using namespace std;

class TrainStation {
public:
    TrainStation();
    void simulateSorting();
    void inputTrainComposition();
    void inputTrainCompositionFromFile(const string& filename); 
    size_t getMainTrackSize() ;

private:
    stack<TrainCar> mainTrack;
    stack<TrainCar> sideTrack1;
    stack<TrainCar> sideTrack2;
};

#endif 
