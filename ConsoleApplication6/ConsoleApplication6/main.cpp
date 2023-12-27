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
        cout << "����-����� �������� �������!" << endl;
    }
    else {
        cout << "����-����� �� ��������!" << endl;
        return EXIT_FAILURE;
    }
    
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "����� ����������: " << duration.count() << " �����������." << endl;

    TrainStation station;
    int choice;

    do {
        cout << "�������� ������ ����� ������:\n";
        cout << "1. ���� � ����������\n";
        cout << "2. ���� �� �����\n";
        cout << "3. ����� �� ���������\n";

        cin >> choice;

        switch (choice) {
        case 1:
            station.inputTrainComposition(); 
            break;
        case 2:
            station.inputTrainCompositionFromFile("input.txt"); 
            break;
        case 3:
            cout << "����� �� ���������.\n";
            break;
        default:
            cerr << "������: ������������ �����.\n";
        }

        if (choice != 3) {
            station.simulateSorting();
        }

    } while (choice != 3);

    return 0;
}
