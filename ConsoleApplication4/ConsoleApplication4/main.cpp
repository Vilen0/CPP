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
    cout << "Введите данные для нового студента:\n";
    cin >> newStudent;
    students.push_back(newStudent);
  
    cout << "Студент успешно добавлен.\n";
}

void updateStudent(vector<STUDENT>& students) {
    int studentIndex;
    cout << "Введите индекс студента, которого вы хотите обновить. (от 0 до " << students.size() - 1 << "): ";
    cin >> studentIndex;

    if (studentIndex >= 0 && studentIndex < students.size()) {
        cout << "Введите обновленные данные для учащегося:\n";
        cin >> students[studentIndex];
        cout << "Студент успешно обновлен.\n";
    }
    else {
        cout << "Неверный индекс. Ни один учащийся не обновлен.\n";
    }
}

void displayAllStudents(const vector<STUDENT>& students) {
    cout << "\nВсе студенты:\n";
    for (const STUDENT& student : students) {
        cout << student << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    auto start_time = chrono::high_resolution_clock::now();

    if (test_addStudent()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cout << "Юнит-тесты не пройдены!" << endl;
    }

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Время выполнения: " << duration.count() << " микросекунд." << endl;
    

    vector<STUDENT> students;
    
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить нового студента\n";
        cout << "2. Обновить данные учащихся\n";
        cout << "3. Отображение учащихся со средней оценкой > 4.0\n";
        cout << "4. Вывести всех студентов\n"; 
        cout << "5. Выход\n";
        cout << "Выберите опцию: ";

        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Введите целое число.\n";
            cout << "Выберите опцию: ";
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
            cout << "\nСтуденты со средним баллом > 4.0:\n";
            for (STUDENT& student : students) {
                double* grades = student.getGrades();
                double average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5.0;

                if (average > 4.0) {
                    cout << student << "\n";
                    found = true;
                }
            }

            if (!found) {
                cout << "Нет учеников со средним баллом > 4.0\n";
            }
            break;
        }
        case 4: {
            displayAllStudents(students);
            break;
        }
        case 5: {
            cout << "Выход из программы.\n";
            return 0;
        }
            
        default: 
            cout << "Неверный выбор. Пожалуйста, введите действительный вариант.\n";
        }
    }

    return 0;
}

