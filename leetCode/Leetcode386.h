#pragma once
#include<iostream>
#include<vector>
#include <string>
#include <algorithm>



class Solution {
public:
    Solution() {};
    std::string intToString(int n) {
        return std::to_string(n);
    }
    int StringToInt(std::string& str) {
        return std::stoi(str);
    }
    char getFirstchar(const std::string& str) {
        return str[0];

    }
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(i + 1);
        }
        std::vector<std::string> result2;
        for (int i = 0; i < n; i++) {
            std::string  str = intToString(result[i]);
            result2.push_back(str);
        }
        std::sort(result2.begin(), result2.end());
        std::vector<int> result3;
        for (int i = 0; i < n; i++) {
            int nt = StringToInt(result2[i]);
            result3.push_back(nt);
        }
        return result3;

    }
};
