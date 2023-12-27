#pragma once

#include "Vect.h"


template<typename T, template<typename> class B> class A {
private:
    B<T> serverObject;

public:
    void addElement(const T& element) {
        serverObject.addElement(element);
    }

    T getElement(int index)  {
        return serverObject.getElement(index);
    }

    size_t getSize()  {
        return serverObject.getSize();
    }
};

