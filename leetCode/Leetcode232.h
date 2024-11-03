#pragma once
#include<iostream>
#include<stack>
#include<string>
#include <queue>
using namespace std;
class MyQueue {
    stack<int>stk1;
    stack<int>stk2;
public:
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty())
            return 1;
        int s = stk2.top();
        stk2.pop();
        return s;
    }

    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty())
            return 1;
        int s = stk2.top();
        return s;
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};



