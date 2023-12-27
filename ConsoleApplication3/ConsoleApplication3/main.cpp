#include <iostream>
#include <string>
#include "A.h"
#include "test.h"
#include <chrono>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    auto start_time = chrono::high_resolution_clock::now();

    if (testVect() && testA()) {
        cout << "����-����� �������� �������!" << endl;
    }
    else {
        cout << "����-����� �� ��������!" << endl;
    }
    
    try {
       
        A<int, Vect> intArray;
        A<double, Vect> doubleArray;
        A<string, Vect> stringArray;

       
        intArray.addElement(10);
        intArray.addElement(20);
        intArray.addElement(30);

        doubleArray.addElement(3.14);
        doubleArray.addElement(2.71);

        stringArray.addElement("Hello");
        stringArray.addElement("World");

        cout << "������ ������� Int: " << intArray.getSize() << endl;
        cout << "������ ������� Double: " << doubleArray.getSize() << endl;
        cout << "������ ������� String: " << stringArray.getSize() << endl;


        cout << "������� � �������� 1 � ������� Int: " << intArray.getElement(1) << endl;
        cout << "������� � �������� 1 � ������� String: " << stringArray.getElement(1) << endl;

        cout << "������� � �������� 2 � ������� String: " << stringArray.getElement(2) << endl;
    }
    catch (const exception& e) {
        cerr << "����������: " << e.what() << endl;
    }
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "����� ����������: " << duration.count() << " �����������." << endl;
    return 0;
}
