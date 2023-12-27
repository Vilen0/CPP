// RailwayStation.cpp
#include "RailwayStation.h"

void RailwayStation::setInputTrack(stack<Wagon>& input) {
    inputTrack = input;
}

void RailwayStation::processWagons() {
    while (!inputTrack.empty()) {
        Wagon currentWagon = inputTrack.top();
        inputTrack.pop();

        // Распределение вагонов по направлениям
        if (currentWagon.getType() == TYPE_A) {
            outputTrackA.push(currentWagon);
        }
        else {
            outputTrackB.push(currentWagon);
        }
    }
}

void RailwayStation::printOutputTracks() const {
    cout << "Состав на направлении A:" << endl;
    stack<Wagon> outputTrackACopy = outputTrackA;
    while (!outputTrackACopy.empty()) {
        cout << outputTrackACopy.top().getType() << " ";
        outputTrackACopy.pop();
    }
    cout << endl;

    cout << "Состав на направлении B:" << endl;
    stack<Wagon> outputTrackBCopy = outputTrackB;
    while (!outputTrackBCopy.empty()) {
        cout << outputTrackBCopy.top().getType() << " ";
        outputTrackBCopy.pop();
    }
    cout << endl;
}
