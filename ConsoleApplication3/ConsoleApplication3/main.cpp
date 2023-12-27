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
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cout << "Юнит-тесты не пройдены!" << endl;
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

        cout << "Размер массива Int: " << intArray.getSize() << endl;
        cout << "Размер массива Double: " << doubleArray.getSize() << endl;
        cout << "Размер массива String: " << stringArray.getSize() << endl;


        cout << "Элемент с индексом 1 в массиве Int: " << intArray.getElement(1) << endl;
        cout << "Элемент с индексом 1 в массиве String: " << stringArray.getElement(1) << endl;

        cout << "Элемент с индексом 2 в массиве String: " << stringArray.getElement(2) << endl;
    }
    catch (const exception& e) {
        cerr << "Исключение: " << e.what() << endl;
    }
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Время выполнения: " << duration.count() << " микросекунд." << endl;
    return 0;
}
