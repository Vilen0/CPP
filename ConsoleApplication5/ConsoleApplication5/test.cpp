#include "Test.h"
#include <fstream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

bool testFileRead() {
    ofstream tempFile("temp_test_file.txt");
    if (!tempFile.is_open()) {
        cerr << "������ ��� �������� ���������� ����� ��� �����!" << endl;
        return false;
    }

    tempFile << "������, ���!\n";
    tempFile << "��� �������� ����.\n";
    tempFile << "�� ��������!\n";

    tempFile.close();

    wifstream testFile("temp_test_file.txt");
    if (!testFile.is_open()) {
        cerr << "������ ��� �������� ���������� ����� ��� �����!" << endl;
        return false;
    }

    vector<wstring> sentences;
    wstring sentence;

    while (getline(testFile, sentence)) {
        sentences.push_back(sentence);
    }


    testFile.close();

    if (sentences.size() != 3) {
        cerr << "������ � ����� ������ �����: ��������� 3 �����������, �������� " << sentences.size() << endl;
        return false;
    }

    return true;
}

bool testSentenceReversal() {
    vector<wstring> testSentences = { L"������, ���!", L"��� �������� ����.", L"�� ��������!" };

    reverse(testSentences.begin(), testSentences.end());
    if (testSentences[0] != L"�� ��������!") {
        cerr << "������ � ����� ��������� �����������: ������ ����������� �� ���������." << endl;
        return false;
    }

    return true;
}

bool Test::runTests() {
    bool allTestsPassed = true;

    if (!testFileRead()) {
        cerr << "���� ������ ����� �� �������!" << endl;
        allTestsPassed = false;
    }

    if (!testSentenceReversal()) {
        cerr << "���� ��������� ����������� �� �������!" << endl;
        allTestsPassed = false;
    }

    /*if (allTestsPassed) {
       
    }*/

    return allTestsPassed;
}

