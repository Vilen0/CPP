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
            cout << "Вагон отправлен на путь 1.\n";
        }
        else {
            sideTrack2.push(currentCar);
            cout << "Вагон отправлен на путь 2.\n";
        }
    }

    cout << "Сортировка завершена.\n";
}

void TrainStation::inputTrainComposition() {
    int totalCars;
    cout << "Введите общее количество вагонов: ";
    cin >> totalCars;

    for (int i = 0; i < totalCars; ++i) {
        int type;
        cout << "Введите тип вагона (1 или 2) для вагона " << i + 1 << ": ";
        cin >> type;

        TrainCar newCar(type);
        mainTrack.push(newCar);
    }

    cout << "Ввод состава с клавиатуры завершен.\n";
}

void TrainStation::inputTrainCompositionFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int type;
        while (inputFile >> type) {
            TrainCar newCar(type);
            mainTrack.push(newCar);
        }

        cout << "Ввод состава из файла завершен.\n";
        inputFile.close();
    }
    else {
        cerr << "Невозможно открыть файл: " << filename << "\n";
    }
}

