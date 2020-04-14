/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        for (index = 0; index < str.length(); index++) {
            if (str[index] != ' ') break;
        }
        if (index == str.length()) return 0;
        if((str[index] != '+') && (str[index] != '-') && !(str[index] >= '0' && str[index] <='9')) return 0;

        long result = 0;
        bool minus = false;
        if (str[index] == '-') {
            minus = true;
            index++;
        } else if(str[index] == '+') {
            index++;
        }

        while (index < str.length()) {
            if (!(str[index] >= '0' && str[index] <= '9')) break;
            if (!minus && (result * 10 + (str[index]-'0') > INT_MAX)) {
                return INT_MAX;
            } else if (minus && (result * 10 + (str[index]-'0')) * -1 < INT_MIN) {
                return INT_MIN;
            }
            result = result * 10 + (str[index] - '0');
            index++;
        }
        if (minus) result *= -1;
        
        return result;
    }
};
// @lc code=end

