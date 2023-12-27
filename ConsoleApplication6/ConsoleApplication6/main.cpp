// main.cpp
#include "TrainStation.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include "TrainStation.h"
#include "Test.h"
using namespace std;
int main() {

    setlocale(LC_ALL, "Russian");

    auto start_time = chrono::high_resolution_clock::now();

    if (Test::runTests()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cout << "Юнит-тесты не пройдены!" << endl;
        return EXIT_FAILURE;
    }
    
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Время выполнения: " << duration.count() << " микросекунд." << endl;

    TrainStation station;
    int choice;

    do {
        cout << "Выберите способ ввода данных:\n";
        cout << "1. Ввод с клавиатуры\n";
        cout << "2. Ввод из файла\n";
        cout << "3. Выйти из программы\n";

        cin >> choice;

        switch (choice) {
        case 1:
            station.inputTrainComposition(); 
            break;
        case 2:
            station.inputTrainCompositionFromFile("input.txt"); 
            break;
        case 3:
            cout << "Выход из программы.\n";
            break;
        default:
            cerr << "Ошибка: Неправильный выбор.\n";
        }

        if (choice != 3) {
            station.simulateSorting();
        }

    } while (choice != 3);

    return 0;
}
