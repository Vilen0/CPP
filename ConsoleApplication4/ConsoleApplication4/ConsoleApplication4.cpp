/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class WORKER {
private:
    string fullName;
    string position;
    int startYear;

public:
    WORKER() : fullName(""), position(""), startYear(0) {}

    WORKER(const string& name, const string& pos, int year)
        : fullName(name), position(pos), startYear(year) {}

    const string& getFullName() const {
        return fullName;
    }

    const string& getPosition() const {
        return position;
    }

    int getStartYear() const {
        return startYear;
    }

    friend ostream& operator<<(ostream& out, const WORKER& worker) {
        out << "Фамилия и инициалы: " << worker.fullName << endl;
        out << "Должность: " << worker.position << endl;
        out << "Год поступления на работу: " << worker.startYear << endl;
        return out;
    }

    friend istream& operator>>(istream& in, WORKER& worker) {
        cout << "Введите фамилию и инициалы работника: ";
        getline(in, worker.fullName);

        cout << "Введите название занимаемой должности: ";
        getline(in, worker.position);

        cout << "Введите год поступления на работу: ";
        in >> worker.startYear;

        // Очистка входного буфера
        in.ignore(numeric_limits<streamsize>::max(), '\n');

        return in;
    }
};

bool compareWorkers(const WORKER& worker1, const WORKER& worker2) {
    return worker1.getFullName() < worker2.getFullName();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int arraySize = 5;
    WORKER workers[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        cout << "Введите информацию о работнике #" << i + 1 << endl;
        cin >> workers[i];
    }

    sort(workers, workers + arraySize, compareWorkers);

    int thresholdYear;
    cout << "Введите стаж, превышение которого нужно найти: ";
    cin >> thresholdYear;

    bool found = false;

    for (int i = 0; i < arraySize; ++i) {
        if (2023 - workers[i].getStartYear() > thresholdYear) {
            cout << "Фамилия работника с стажем более " << thresholdYear << " лет: " << workers[i].getFullName() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет работников со стажем более " << thresholdYear << " лет." << endl;
    }

    return 0;
}*/