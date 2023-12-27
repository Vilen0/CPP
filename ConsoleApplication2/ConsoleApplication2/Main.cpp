#include <iostream>
#include "Tests.h"
#include <chrono>
#include "T1.h"
#include "T2.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    
    auto start_time = chrono::high_resolution_clock::now();
   
    
   if (testT1() && testT2()) {
       cout << "Юнит-тесты пройдены успешно!" << endl;
   }
   else {
       cerr << "Юнит-тесты не пройдены!" << endl;
   }
   
   
   auto end_time = chrono::high_resolution_clock::now();

   auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

   cout << "Время выполнения Юнит-тестов: " << duration.count() << " микросекунд." << endl;

    BaseClass* obj = nullptr;
    int choice;
    int choice2;

    do {
        cout << "\n1. Создать и выполнить операции для T1 (Символьная строка)" << endl;
        cout << "2. Создать и выполнить операции для T2 (Десятичная строка)" << endl;
        cout << "0. Выход \n" << endl;

        cout << "Введите команду: \n";
        cin >> choice;

        switch (choice) {
        case 0:{
            cout << "Выход из программы." << endl;
            break;
        }
        case 1: {
            cout << "\n1. Сложение объектов класса T1 (Символьная строка)" << endl;
            cout << "2. Вычитание объектов класса T1 (Символьная строка)" << endl;
            cout << "0. Назад \n" << endl;
            cout << "Введите команду: \n";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    string id1, value1;
                    cout << "Введите ID для T1: ";
                    cin >> id1;
                    cout << "Введите строку для T1: ";
                    cin >> value1;
                    T1 s1(id1, value1);
                    
                    string id2, value2;
                    cout << "Введите ID для T2: ";
                    cin >> id2;
                    cout << "Введите строку для T2: ";
                    cin >> value2;
                    T1 s2(id2, value2);

                    T1 result = s1 + s2;

        
                    cout << "Результат сложения: ";
                    result.ShowValue();
                    break;
                }
                case 2: {
                    string id1, value1;
                    cout << "Введите ID для T1: ";
                    cin >> id1;
                    cout << "Введите строку для T1: ";
                    cin >> value1;
                    T1 s1(id1, value1);

                    string id2, value2;
                    cout << "Введите ID для T2: ";
                    cin >> id2;
                    cout << "Введите строку для T2: ";
                    cin >> value2;
                    T1 s2(id2, value2);

                    T1 result = s1 - s2;

                    cout << "Результат вычитания: ";
                    result.ShowValue();

                    break;
                }
                case 0:
                    cout << "Выход из программы." << endl;
                    break;
                default:
                    cout << "Неизвестная команда." << endl;
            }
            break;
        }
        case 2: {
            cout << "\n1. Сложение объектов класса T2 (Десятичная строка)" << endl;
            cout << "2. Вычитание объектов класса T2 (Десятичная строка)" << endl;
            cout << "0. Назад \n" << endl;
            cout << "Введите команду: \n";
            cin >> choice2;
            switch (choice2) {
            case 1: {
                string id1;
                int value1;
                cout << "Введите ID для T2: ";
                cin >> id1;
                cout << "Введите число для T2: ";
                cin >> value1;
                T2 s1(id1, value1);

                string id2;
                int value2;
                cout << "Введите ID для T2: ";
                cin >> id2;
                cout << "Введите число для T2: ";
                cin >> value2;
                T2 s2(id2, value2);

                T2 result = s1 + s2;

               
                cout << "Результат сложения: ";
                result.ShowValue();
                result.ShowBin();
                result.ShowOct();
                result.ShowHex();
                break;
            }
            case 2: {
                string id1;
                int value1;
                cout << "Введите ID для T2: ";
                cin >> id1;
                cout << "Введите число для T2: ";
                cin >> value1;
                T2 s1(id1, value1);

                string id2;
                int value2;
                cout << "Введите ID для T2: ";
                cin >> id2;
                cout << "Введите число для T2: ";
                cin >> value2;
                T2 s2(id2, value2);

                T2 result = s1 - s2;

                
                cout << "Результат вычитания: ";
                result.ShowValue();
                result.ShowBin();
                result.ShowOct();
                result.ShowHex();
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неизвестная команда." << endl;
            }
            break;

        }
        
        default:
            cout << "Неизвестная команда." << endl;
        }

    } while (choice != 0);

    return 0;
}