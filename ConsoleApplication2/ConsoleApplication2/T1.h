#ifndef T1_H
#define T1_H

#include "BaseClass.h"
using namespace std;

class T1 : public BaseClass {
public:
    T1(string id, string value);

    void ShowValue() override;
 
    T1 operator+(const T1& other) ;
    T1 operator-(const T1& other) ;

    string value;
};

#endif

