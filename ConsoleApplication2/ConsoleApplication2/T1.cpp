#include "T1.h"
#include <bitset>
using namespace std;

T1::T1(string id, string value) : BaseClass(id), value(value) {}

void T1::ShowValue() {
    cout << value << endl;
}

T1 T1::operator+(const T1& other)  {
    return T1(this->id + other.id, this->value + other.value);
}

T1 T1::operator-(const T1& other)  {
    size_t pos = value.find(other.value);
    if (pos != string::npos) {
        return T1(this->id, value.substr(0, pos) + value.substr(pos + other.value.length()));
    }
    else {
        return *this;
    }
}

