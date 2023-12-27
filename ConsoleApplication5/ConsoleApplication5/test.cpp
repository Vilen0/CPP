#include "Test.h"
#include <fstream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

bool testFileRead() {
    ofstream tempFile("temp_test_file.txt");
    if (!tempFile.is_open()) {
        cerr << "Ошибка при создании временного файла для теста!" << endl;
        return false;
    }

    tempFile << "Привет, мир!\n";
    tempFile << "Это тестовый файл.\n";
    tempFile << "До свидания!\n";

    tempFile.close();

    wifstream testFile("temp_test_file.txt");
    if (!testFile.is_open()) {
        cerr << "Ошибка при открытии временного файла для теста!" << endl;
        return false;
    }

    vector<wstring> sentences;
    wstring sentence;

    while (getline(testFile, sentence)) {
        sentences.push_back(sentence);
    }


    testFile.close();

    if (sentences.size() != 3) {
        cerr << "Ошибка в тесте чтения файла: ожидалось 3 предложения, получено " << sentences.size() << endl;
        return false;
    }

    return true;
}

bool testSentenceReversal() {
    vector<wstring> testSentences = { L"Привет, мир!", L"Это тестовый файл.", L"До свидания!" };

    reverse(testSentences.begin(), testSentences.end());
    if (testSentences[0] != L"До свидания!") {
        cerr << "Ошибка в тесте разворота предложений: первое предложение не совпадает." << endl;
        return false;
    }

    return true;
}

bool Test::runTests() {
    bool allTestsPassed = true;

    if (!testFileRead()) {
        cerr << "Тест чтения файла не пройден!" << endl;
        allTestsPassed = false;
    }

    if (!testSentenceReversal()) {
        cerr << "Тест разворота предложений не пройден!" << endl;
        allTestsPassed = false;
    }

    /*if (allTestsPassed) {
       
    }*/

    return allTestsPassed;
}

