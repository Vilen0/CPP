#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
using namespace std;

class STUDENT {
private:
    string name;
    int groupNumber;
    double grades[5];
    //string gradesInput;
    //char* pName;

public:
    STUDENT() {};
    STUDENT(string n, int group, double* g);

     string& getName() ;
    int getGroupNumber() ;
     double* getGrades() ;

    friend ostream& operator<<(ostream& os, const STUDENT& student);
    friend istream& operator>>(istream& is, STUDENT& student);
};

#endif 
