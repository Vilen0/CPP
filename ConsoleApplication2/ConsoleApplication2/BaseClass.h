#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
using namespace std;


class BaseClass {
public:
    BaseClass(string id) {
        this->id = id;
    }

    void ShowId() {
        cout << "ID: " << id << endl;
    }

    virtual void ShowValue() {};

protected:
    string id;
};

#endif

