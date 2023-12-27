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
        out << "������� � ��������: " << worker.fullName << endl;
        out << "���������: " << worker.position << endl;
        out << "��� ����������� �� ������: " << worker.startYear << endl;
        return out;
    }

    friend istream& operator>>(istream& in, WORKER& worker) {
        cout << "������� ������� � �������� ���������: ";
        getline(in, worker.fullName);

        cout << "������� �������� ���������� ���������: ";
        getline(in, worker.position);

        cout << "������� ��� ����������� �� ������: ";
        in >> worker.startYear;

        // ������� �������� ������
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
        cout << "������� ���������� � ��������� #" << i + 1 << endl;
        cin >> workers[i];
    }

    sort(workers, workers + arraySize, compareWorkers);

    int thresholdYear;
    cout << "������� ����, ���������� �������� ����� �����: ";
    cin >> thresholdYear;

    bool found = false;

    for (int i = 0; i < arraySize; ++i) {
        if (2023 - workers[i].getStartYear() > thresholdYear) {
            cout << "������� ��������� � ������ ����� " << thresholdYear << " ���: " << workers[i].getFullName() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "��� ���������� �� ������ ����� " << thresholdYear << " ���." << endl;
    }

    return 0;
}*/