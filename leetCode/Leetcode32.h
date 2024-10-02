#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> stk;
        int maxLen = 0;
        stk.push(-1);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {

                stk.push(i);
            }
            else {

                stk.pop();

                if (!stk.empty()) {

                    maxLen = max(maxLen, i - stk.top());
                }
                else {

                    stk.push(i);
                }
            }
        }

        return maxLen;
    }
};