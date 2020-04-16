/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string s = "1";
        int p1, p2;
        for (int i = 0; i < n-1; i++) {
            string temp = "";
            p1 = 0;
            p2 = 0;
            while (p2 < s.length()) {
                if (s[p1] == s[p2])
                    p2++;
                else {
                    temp += to_string(p2 - p1);
                    temp += s[p1];
                    p1 = p2;
                }
            }
            cout << p1 << " " << p2 << endl;
            temp += to_string(p2 - p1);
            temp += s[p1];

            s = temp;
        }
        return s;
    }
};
// @lc code=end

