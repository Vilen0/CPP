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
       cout << "����-����� �������� �������!" << endl;
   }
   else {
       cerr << "����-����� �� ��������!" << endl;
   }
   
   
   auto end_time = chrono::high_resolution_clock::now();

   auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

   cout << "����� ���������� ����-������: " << duration.count() << " �����������." << endl;

    BaseClass* obj = nullptr;
    int choice;
    int choice2;

    do {
        cout << "\n1. ������� � ��������� �������� ��� T1 (���������� ������)" << endl;
        cout << "2. ������� � ��������� �������� ��� T2 (���������� ������)" << endl;
        cout << "0. ����� \n" << endl;

        cout << "������� �������: \n";
        cin >> choice;

        switch (choice) {
        case 0:{
            cout << "����� �� ���������." << endl;
            break;
        }
        case 1: {
            cout << "\n1. �������� �������� ������ T1 (���������� ������)" << endl;
            cout << "2. ��������� �������� ������ T1 (���������� ������)" << endl;
            cout << "0. ����� \n" << endl;
            cout << "������� �������: \n";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    string id1, value1;
                    cout << "������� ID ��� T1: ";
                    cin >> id1;
                    cout << "������� ������ ��� T1: ";
                    cin >> value1;
                    T1 s1(id1, value1);
                    
                    string id2, value2;
                    cout << "������� ID ��� T2: ";
                    cin >> id2;
                    cout << "������� ������ ��� T2: ";
                    cin >> value2;
                    T1 s2(id2, value2);

                    T1 result = s1 + s2;

        
                    cout << "��������� ��������: ";
                    result.ShowValue();
                    break;
                }
                case 2: {
                    string id1, value1;
                    cout << "������� ID ��� T1: ";
                    cin >> id1;
                    cout << "������� ������ ��� T1: ";
                    cin >> value1;
                    T1 s1(id1, value1);

                    string id2, value2;
                    cout << "������� ID ��� T2: ";
                    cin >> id2;
                    cout << "������� ������ ��� T2: ";
                    cin >> value2;
                    T1 s2(id2, value2);

                    T1 result = s1 - s2;

                    cout << "��������� ���������: ";
                    result.ShowValue();

                    break;
                }
                case 0:
                    cout << "����� �� ���������." << endl;
                    break;
                default:
                    cout << "����������� �������." << endl;
            }
            break;
        }
        case 2: {
            cout << "\n1. �������� �������� ������ T2 (���������� ������)" << endl;
            cout << "2. ��������� �������� ������ T2 (���������� ������)" << endl;
            cout << "0. ����� \n" << endl;
            cout << "������� �������: \n";
            cin >> choice2;
            switch (choice2) {
            case 1: {
                string id1;
                int value1;
                cout << "������� ID ��� T2: ";
                cin >> id1;
                cout << "������� ����� ��� T2: ";
                cin >> value1;
                T2 s1(id1, value1);

                string id2;
                int value2;
                cout << "������� ID ��� T2: ";
                cin >> id2;
                cout << "������� ����� ��� T2: ";
                cin >> value2;
                T2 s2(id2, value2);

                T2 result = s1 + s2;

               
                cout << "��������� ��������: ";
                result.ShowValue();
                result.ShowBin();
                result.ShowOct();
                result.ShowHex();
                break;
            }
            case 2: {
                string id1;
                int value1;
                cout << "������� ID ��� T2: ";
                cin >> id1;
                cout << "������� ����� ��� T2: ";
                cin >> value1;
                T2 s1(id1, value1);

                string id2;
                int value2;
                cout << "������� ID ��� T2: ";
                cin >> id2;
                cout << "������� ����� ��� T2: ";
                cin >> value2;
                T2 s2(id2, value2);

                T2 result = s1 - s2;

                
                cout << "��������� ���������: ";
                result.ShowValue();
                result.ShowBin();
                result.ShowOct();
                result.ShowHex();
                break;
            }
            case 0:
                cout << "����� �� ���������." << endl;
                break;
            default:
                cout << "����������� �������." << endl;
            }
            break;

        }
        
        default:
            cout << "����������� �������." << endl;
        }

    } while (choice != 0);

    return 0;
}