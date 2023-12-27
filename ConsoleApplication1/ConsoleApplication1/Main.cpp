#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "CMyStack.h"
#include "CMyStackUnitTest.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto start_time = chrono::high_resolution_clock::now();

    CMyStackUnitTest::RunTests();

    auto end_time = chrono::high_resolution_clock::now();
   
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
   
    cout << "��� ��������� ���������. ����� ����������: " << duration.count() << " �����������." << endl;

    while (true) {
        CMyStack TrainBase, OneTrain, TwoTrain;

        cout << "�������� �������� ������ (0 - �� �����, 1 - � ����������, 2 - �����): ";
        int choice;
        cin >> choice;

        if (choice == 2) {
            break; 
        }
        else if (choice == 0) {
            ifstream in("trains.txt", ios::in);

            if (!in.is_open()) {
                cout << "���������� ������� ���� trains.txt ��� ������." << endl;
                return 1;
            }

            
            while (!in.eof()) {
                int pr;
                in >> pr;
                TrainBase.Push(pr);
            }

            in.close();
        }
        else if (choice == 1) {
            
            cout << "������� �����, �������������� ���� ������� (������� -1 ��� ���������� �����):\n";
            int input;
            while (true) {
                if (cin >> input) {
                    if (input == -1) {
                        break; 
                    }
                    else if (input == 1 || input == 2) {
                        TrainBase.Push(input);
                    }
                    else {
                        cout << "������������ ����. ������� ������ 1, 2 ��� -1." << endl;
                    }
                }
                else {
                    cout << "������������ ������. ����������, ������� �����." << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                }
            }
        }
 

        else {
            cout << "�������� ����� ��������� ������." << endl;
            return 1;
        }

        while (!TrainBase.isEmpty()) {
            int pr = TrainBase.Pop();
            switch (pr) {
            case 1:
                OneTrain.Push(pr);
                break;
            case 2:
                TwoTrain.Push(pr);
                break;
            }
        }

        cout << "������ �����������: ";
        OneTrain.Print();

        cout << "������ �����������: ";
        TwoTrain.Print();
    }

    cout << "��������� ���������." << endl;

    cin.get(); 
    return 0;
}
