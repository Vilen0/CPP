#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale> 
#include "test.h"
#include <chrono>
#include <Windows.h>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    auto start_time = chrono::high_resolution_clock::now();

    if (Test::runTests()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cerr << "Юнит-тесты не пройдены!" << endl;
        return 1;
    }

    wifstream inputFile("input.txt");
    //inputFile.imbue(locale(""));

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    vector<wstring> sentences;
    wstring sentence;

    while (getline(inputFile, sentence)) {
        sentences.push_back(sentence);
    }

    inputFile.close();

    cout << "Предложения в обратном порядке:" << endl;
    reverse(sentences.begin(), sentences.end());
    for (const wstring& sentence : sentences) {
        wcout << sentence << endl;
    }

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Время выполнения: " << duration.count() << " микросекунд." << endl;

    return 0;
}

