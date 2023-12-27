#include "Tests.h"
#include "T1.h"
#include "T2.h"
#include <bitset>
#include <regex>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

bool testT1() {

    cout << "Запуск теста T1..." << endl;

    T1 s1("id1", "Hello");
    T1 s2("id2", " World");

    T1 result = s1 + s2;

    return result.value == "Hello World";
}

bool testT2() {
    cout << "Запуск теста T2..." << endl;
    T2 t1("testID1", 10);
    T2 t2("testID2", 20);
    T2 result = t1 + t2;


    return result.decimalValue== 30;
}

