#include "CMyStackUnitTest.h"
#include <fstream>
#include <cassert>
#include <iostream>
using namespace std;

void CMyStackUnitTest::RunTests() {
    TestFileInput();
    TestKeyboardInput();
    
}

void CMyStackUnitTest::TestFileInput() {
    cout << "Запуск теста с файла...\n";
    CMyStack stack;

    ofstream outFile("testfile.txt");
    outFile << "1 2 2 1 -1";
    outFile.close();

    ifstream inFile("testfile.txt", ios::in);
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            int pr;
            inFile >> pr;
            stack.Push(pr);
        }
        inFile.close();
    }

    
    cout << "Тест с файла: Пройдено\n";
}

#include <sstream>

void CMyStackUnitTest::TestKeyboardInput() {
    cout << "Запуск теста с клавиатуры...\n";

    stringstream input("1 2 -1");
    streambuf* origCin = cin.rdbuf(input.rdbuf());

    CMyStack stack;

    int inputNumber;
    while (cin >> inputNumber && inputNumber != -1) {
        stack.Push(inputNumber);
    }
    assert(!stack.isEmpty());
    assert(stack.Pop() == 2);
    assert(stack.Pop() == 1);

    cin.rdbuf(origCin);

    cout << "Тест с клавиатуры: Пройдено\n";
}

