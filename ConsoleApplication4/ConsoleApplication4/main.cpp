#include "test.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include "student.h"
#include <algorithm>
#include <vector>
using namespace std;
using namespace chrono;


void addStudent(vector<STUDENT>& students) {
    STUDENT newStudent;
    cout << "������� ������ ��� ������ ��������:\n";
    cin >> newStudent;
    students.push_back(newStudent);
  
    cout << "������� ������� ��������.\n";
}

void updateStudent(vector<STUDENT>& students) {
    int studentIndex;
    cout << "������� ������ ��������, �������� �� ������ ��������. (�� 0 �� " << students.size() - 1 << "): ";
    cin >> studentIndex;

    if (studentIndex >= 0 && studentIndex < students.size()) {
        cout << "������� ����������� ������ ��� ���������:\n";
        cin >> students[studentIndex];
        cout << "������� ������� ��������.\n";
    }
    else {
        cout << "�������� ������. �� ���� �������� �� ��������.\n";
    }
}

void displayAllStudents(const vector<STUDENT>& students) {
    cout << "\n��� ��������:\n";
    for (const STUDENT& student : students) {
        cout << student << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    auto start_time = chrono::high_resolution_clock::now();

    if (test_addStudent()) {
        cout << "����-����� �������� �������!" << endl;
    }
    else {
        cout << "����-����� �� ��������!" << endl;
    }

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "����� ����������: " << duration.count() << " �����������." << endl;
    

    vector<STUDENT> students;
    
    while (true) {
        cout << "\n����:\n";
        cout << "1. �������� ������ ��������\n";
        cout << "2. �������� ������ ��������\n";
        cout << "3. ����������� �������� �� ������� ������� > 4.0\n";
        cout << "4. ������� ���� ���������\n"; 
        cout << "5. �����\n";
        cout << "�������� �����: ";

        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�������� ����. ������� ����� �����.\n";
            cout << "�������� �����: ";
        }

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            updateStudent(students);
            break;
        case 3: {
            bool found = false;
            cout << "\n�������� �� ������� ������ > 4.0:\n";
            for (STUDENT& student : students) {
                double* grades = student.getGrades();
                double average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5.0;

                if (average > 4.0) {
                    cout << student << "\n";
                    found = true;
                }
            }

            if (!found) {
                cout << "��� �������� �� ������� ������ > 4.0\n";
            }
            break;
        }
        case 4: {
            displayAllStudents(students);
            break;
        }
        case 5: {
            cout << "����� �� ���������.\n";
            return 0;
        }
            
        default: 
            cout << "�������� �����. ����������, ������� �������������� �������.\n";
        }
    }

    return 0;
}

