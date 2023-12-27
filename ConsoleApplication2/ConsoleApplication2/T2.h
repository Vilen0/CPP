#ifndef T2_H
#define T2_H

#include "BaseClass.h"
using namespace std;

class T2 : public BaseClass {
public:
    T2(string id, int decimalValue);

    void ShowBin();
    void ShowOct();
    void ShowHex();
    void ShowValue() override;

    T2 operator+(const T2& other) ;
    T2 operator-(const T2& other) ;

    int decimalValue;
};

#endif 