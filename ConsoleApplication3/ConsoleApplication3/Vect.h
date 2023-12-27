#pragma once

#include <list>
using namespace std;

template<typename T> class Vect {
private:
    list<T> data;
public:
    void addElement(const T& element)  {
        data.push_back(element);
    }

    T getElement(int index)   {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Индекс за пределами");
        }
        auto it = data.begin();
        advance(it, index);
        return *it;
    }

    size_t getSize()  {
        return data.size();
    }
};

