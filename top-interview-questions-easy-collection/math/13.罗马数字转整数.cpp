/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> alp = {{'I', 1}, {'V', 5}, {'X', 10},
         {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int num = 0;
        if (s.length() == 1) {
            num += alp[s[0]];
        } else {
            for (int i = 0; i < s.length()-1; i++) {
                if (alp[s[i]] >= alp[s[i+1]]) {
                    num += alp[s[i]];
                } else {
                    num -= alp[s[i]];
                }
            }
            num += alp[s[s.length() - 1]];
        }
        return num;
    }
};
// @lc code=end

