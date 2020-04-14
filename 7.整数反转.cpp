/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int result=0;
        while (x != 0) {
            if (result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
            result = result*10 + x%10;
            x /= 10;
        }
        return result;
    }
};
// @lc code=end

