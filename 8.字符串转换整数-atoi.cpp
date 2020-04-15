/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int getcol(char c) {
            if (c == ' ') return 0;
            else if (c == '-' || c == '+') return 1;
            else if (isdigit(c)) return 2;
            else
                return 3;
        }

    int myAtoi(string str) {
        unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}},
        };

        long result = 0;
        bool sign = true;

        string state = "start";
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            cout << c << " " << getcol(c) << endl;
            state = table[state][getcol(c)];
            if (state == "signed") {
                sign = (c == '-'?false:true);
            } else if (state == "in_number") {
                if (sign && (result * 10 + (c - '0') > INT_MAX)) {
                    result = INT_MAX;
                    break;
                } else if (!sign && ((result * 10) + (c - '0'))*-1 < INT_MIN) {
                    result = INT_MIN;
                    break;
                } else {
                    result = result * 10 + (c - '0');
                }
            } else if (state == "end") {
                break;
            }
        }

        result = (sign ? result : result * -1);
        return result;
    }
};
// @lc code=end

