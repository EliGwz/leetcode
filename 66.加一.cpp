/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        bool carry = false;

        if (digits[digits.size()-1] + add == 10) {
            add = 1;
            digits[digits.size() - 1] = 0;
        } else {
            add = 0;
            digits[digits.size() - 1]++;
        }


        for (int i = digits.size()-2; i >= 0; i--) {
            digits[i] = (digits[i] + add) % 10;
        }

        if (add == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

