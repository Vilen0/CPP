// student.cpp
#include "student.h"
#include <string>
#include <iostream>
#include <limits>
#include "windows.h"

using namespace std;

//STUDENT::STUDENT() : groupNumber(0) {
//    for (int i = 0; i < 5; ++i) {
//        grades[i] = 0.0;
//    }
//}

STUDENT::STUDENT(string n, int group, double* g) : name(n), groupNumber(group) {
    for (int i = 0; i < 5; ++i) {
        grades[i] = g[i];
    }
}

 string& STUDENT::getName()  {
    return name;
}

int STUDENT::getGroupNumber()  {
    return groupNumber;
}

 double* STUDENT::getGrades()  {
    return grades;
}

ostream& operator<<(ostream& os, const STUDENT& student) {
    
    os << "\n���: " << student.name << "\n����� ������: " << student.groupNumber << "\n������: ";
    for (int i = 0; i < 5; ++i) {
        os << student.grades[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, STUDENT& student) {
    cout << "������� ��� ��������: ";
    getline(is >> ws, student.name);  

    cout << "������� ����� ������: ";
    is >> student.groupNumber;

    cout << "������� ������ (5 ����): ";
    for (int i = 0; i < 5; ++i) {
        is >> student.grades[i];
    }
    return is;
}

