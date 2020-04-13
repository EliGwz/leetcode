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

        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] + add == 10) {
                add = 1;
                digits[i] = 0;
            } else {
                digits[i] += add;
                return digits;
            }
        }

        if (add == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

