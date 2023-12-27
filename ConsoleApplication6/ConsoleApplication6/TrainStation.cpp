// TrainStation.cpp
#include "TrainStation.h"
#include "TrainCar.h"
#include <iostream>
#include <fstream>
using namespace std;
TrainStation::TrainStation() {}

size_t TrainStation::getMainTrackSize()  {
    return mainTrack.size();
}

void TrainStation::simulateSorting() {

    stack<TrainCar> tempStack; 

    while (!mainTrack.empty()) {
        tempStack.push(mainTrack.top());
        mainTrack.pop();
    }

    while (!tempStack.empty()) {
        TrainCar currentCar = tempStack.top();
        tempStack.pop();

        if (currentCar.getType() == 1) {
            sideTrack1.push(currentCar);
            cout << "����� ��������� �� ���� 1.\n";
        }
        else {
            sideTrack2.push(currentCar);
            cout << "����� ��������� �� ���� 2.\n";
        }
    }

    cout << "���������� ���������.\n";
}

void TrainStation::inputTrainComposition() {
    int totalCars;
    cout << "������� ����� ���������� �������: ";
    cin >> totalCars;

    for (int i = 0; i < totalCars; ++i) {
        int type;
        cout << "������� ��� ������ (1 ��� 2) ��� ������ " << i + 1 << ": ";
        cin >> type;

        TrainCar newCar(type);
        mainTrack.push(newCar);
    }

    cout << "���� ������� � ���������� ��������.\n";
}

void TrainStation::inputTrainCompositionFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int type;
        while (inputFile >> type) {
            TrainCar newCar(type);
            mainTrack.push(newCar);
        }

        cout << "���� ������� �� ����� ��������.\n";
        inputFile.close();
    }
    else {
        cerr << "���������� ������� ����: " << filename << "\n";
    }
}

