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

int main() {

    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);
    myStack->push(5);
    myStack->push(6);
    myStack->push(7);
    myStack->push(8);
    int y = myStack->pop();
    int  x = myStack->top();
    int yy = myStack->pop();
    int  xy = myStack->top();
    cout << y << x << yy << xy;
    return 0;
}