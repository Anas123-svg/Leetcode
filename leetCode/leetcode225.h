#pragma once
#include<iostream>
#include<stdexcept>
#include<queue>
using namespace std;
class MyStack {
    queue<int> a;
    queue<int> b;

public:
    MyStack() {}

    void push(int x) {
        a.push(x);
    }

    int pop() {
        if (a.empty() && b.empty()) {
            throw std::out_of_range("out of range");
        }
        while (a.size() > 1)
        {
            b.push(a.front());
            a.pop();
        }
        int value = a.front();
        a.pop();
        swap(a, b);

        return value;

    }

    int top() {
        if (a.empty() && b.empty()) {
            throw std::out_of_range("out of range");
        }
        while (a.size() > 1)
        {
            b.push(a.front());
            a.pop();
        }
        int value = a.front();
        b.push(a.front());
        a.pop();
        swap(a, b);

        return value;
    }

    bool empty() {
        return a.empty() && b.empty();

    }
};