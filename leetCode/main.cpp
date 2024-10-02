#include<iostream>
#include "leetcode225.h"
#include "Leetcode386.h"
#include<stack>
#include<string>



using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char>stk_s;
    stack<char>stk_t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
            if (!stk_s.empty())
                stk_s.pop();
        }
        else {
            stk_s.push(s[i]);
        }
    }

    for (int i = 0; i < t.length(); i++) {
        if (t[i] == '#') {
            if (!stk_t.empty())
                stk_t.pop();
        }
        else {
            stk_t.push(t[i]);
        }
    }
    bool y = true;
    while (!stk_s.empty() && !stk_t.empty()) {
        if (stk_s.top() != stk_t.top()) return false;
        stk_s.pop();
        stk_t.pop();
    }

    return stk_s.empty() && stk_t.empty();
}


int main() {

    string s = "xywrrmp";
    string t = "xywrrmu#p";
    bool y = backspaceCompare(s,t) ;
    if (y)
        cout << "y";
    else {
        cout << "n";
    }
    return 0;
}