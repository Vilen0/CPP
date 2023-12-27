#include "CMyStack.h"
#include <iostream>
using namespace std;

CMyStack::CMyStack() : top(nullptr) {}

void CMyStack::Push(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->p = top;
    top = pv;
}

int CMyStack::Pop() {
    if (isEmpty()) {
        return -1; 
    }
    int temp = top->d;
    Node* pv = top;
    top = top->p;
    delete pv;
    return temp;
}

bool CMyStack::isEmpty() {
    return !top;
}

void CMyStack::Print() {
    while (!isEmpty()) {
        cout << Pop() << ' ';
    }

    cout << endl;
}

CMyStack::~CMyStack() {
    while (top) {
        Node* pv = top;
        top = top->p;
        delete pv;
    }
}
