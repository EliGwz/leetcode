/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int du_count = 0;
        if (nums.size() < 1) {
            return nums.size();
        }
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                du_count++;
            } else {
                nums[i-du_count] = nums[i];
            }
        }

        return nums.size() - du_count; 
    }
};
// @lc code=end

