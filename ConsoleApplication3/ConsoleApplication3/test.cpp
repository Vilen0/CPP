#include <iostream>
#include <cassert>
#include "Vect.h"
#include "A.h"

bool testVect() {
    Vect<int> intVect;
    intVect.addElement(42);
    assert(intVect.getSize() == 1);

    intVect.addElement(10);
    intVect.addElement(20);
    assert(intVect.getSize() == 3);
    assert(intVect.getElement(0) == 42);
    assert(intVect.getElement(1) == 10);
    assert(intVect.getElement(2) == 20);
    return true;
}

bool testA() {
    A<int, Vect> intArray;
    intArray.addElement(10);
    intArray.addElement(20);
    assert(intArray.getSize() == 2);
    assert(intArray.getElement(0) == 10);
    assert(intArray.getElement(1) == 20);

    intArray.addElement(30);
    assert(intArray.getSize() == 3);

    try {
        intArray.getElement(5);
        assert(false);
    }
    catch (const out_of_range& e) {
        assert(true);
    }
    return true;
}

