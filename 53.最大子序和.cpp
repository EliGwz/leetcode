/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum >= 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }

            if (sum > max)
                max = sum;
        }
        return max;
    }
};
// @lc code=end

