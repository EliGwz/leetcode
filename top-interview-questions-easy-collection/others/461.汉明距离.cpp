/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += (((x >> i) & 1) ^ ((y >> i) & 1));
        }
        return count;
    }
};
// @lc code=end

