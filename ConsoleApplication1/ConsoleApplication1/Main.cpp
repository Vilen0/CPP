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
   
    cout << "Все испытания завершены. Время выполнения: " << duration.count() << " микросекунд." << endl;

    while (true) {
        CMyStack TrainBase, OneTrain, TwoTrain;

        cout << "Выберите источник данных (0 - из файла, 1 - с клавиатуры, 2 - выход): ";
        int choice;
        cin >> choice;

        if (choice == 2) {
            break; 
        }
        else if (choice == 0) {
            ifstream in("trains.txt", ios::in);

            if (!in.is_open()) {
                cout << "Невозможно открыть файл trains.txt для чтения." << endl;
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
            
            cout << "Введите числа, представляющие типы поездов (введите -1 для завершения ввода):\n";
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
                        cout << "Недопустимый ввод. Введите только 1, 2 или -1." << endl;
                    }
                }
                else {
                    cout << "Недопустимый символ. Пожалуйста, введите число." << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                }
            }
        }
 

        else {
            cout << "Неверный выбор источника данных." << endl;
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

        cout << "Первое направление: ";
        OneTrain.Print();

        cout << "Второе направление: ";
        TwoTrain.Print();
    }

    cout << "Программа завершена." << endl;

    cin.get(); 
    return 0;
}
