// RailwayStation.cpp
#include "RailwayStation.h"

void RailwayStation::setInputTrack(stack<Wagon>& input) {
    inputTrack = input;
}

void RailwayStation::processWagons() {
    while (!inputTrack.empty()) {
        Wagon currentWagon = inputTrack.top();
        inputTrack.pop();

        // ������������� ������� �� ������������
        if (currentWagon.getType() == TYPE_A) {
            outputTrackA.push(currentWagon);
        }
        else {
            outputTrackB.push(currentWagon);
        }
    }
}

void RailwayStation::printOutputTracks() const {
    cout << "������ �� ����������� A:" << endl;
    stack<Wagon> outputTrackACopy = outputTrackA;
    while (!outputTrackACopy.empty()) {
        cout << outputTrackACopy.top().getType() << " ";
        outputTrackACopy.pop();
    }
    cout << endl;

    cout << "������ �� ����������� B:" << endl;
    stack<Wagon> outputTrackBCopy = outputTrackB;
    while (!outputTrackBCopy.empty()) {
        cout << outputTrackBCopy.top().getType() << " ";
        outputTrackBCopy.pop();
    }
    cout << endl;
}
