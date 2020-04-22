/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else {
            int maxCur = 0, maxPre = 0;
            for (int i=0; i<nums.size(); i++) {
                int temp = maxCur;
                maxCur = maxPre+nums[i]>maxCur?maxPre+nums[i]:maxCur;
                maxPre = temp;
            }
            return maxCur;
        }

    }
};
// @lc code=end

