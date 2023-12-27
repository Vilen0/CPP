#include "T2.h"
#include <bitset>
#include <iostream>
using namespace std;

T2::T2(string id, int decimalValue) : BaseClass(id), decimalValue(decimalValue) {}

void T2::ShowBin()  {
    bitset<32> binary(decimalValue);
    cout << "��������: " << binary.to_string() << endl;
}

void T2::ShowOct()  {
    cout << "������������: " << oct << decimalValue << dec << endl;
}

void T2::ShowHex()  {
    cout << "�����������������: " << hex << decimalValue << dec << endl;
}

void T2::ShowValue() {
    cout << "��������: " << decimalValue << endl;
}

T2 T2::operator+(const T2& other)  {
    return T2(this->id, this->decimalValue + other.decimalValue);
}

T2 T2::operator-(const T2& other)  {
    return T2(this->id, this->decimalValue - other.decimalValue);
}

