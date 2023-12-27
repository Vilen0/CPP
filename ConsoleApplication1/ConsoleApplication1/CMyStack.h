#pragma once

class CMyStack {
public:
    CMyStack();
    ~CMyStack();
    void Push(int d);
    int Pop();
    bool isEmpty();
    void Print();


private:
    struct Node {
        int d;
        Node* p;
    };

    Node* top;

};
