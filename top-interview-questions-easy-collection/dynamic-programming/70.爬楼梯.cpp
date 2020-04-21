/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else {
            int a = 1, b = 2, temp;
            for (int i = 0; i < n - 2; i++) {
                temp = a + b;
                a = b;
                b = temp;
            }
            return temp;
        }
    }
};
// @lc code=end

