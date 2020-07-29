/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, mid = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < small) {
                small = nums[i];
            } else if (nums[i] > small && nums[i] < mid) {
                mid = nums[i];
            } else if (nums[i] > mid){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

