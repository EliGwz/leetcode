/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index1 = 0, index2 = 0;
        while (index2 < nums.size()) {
            if (nums[index2] != 0) {
                nums[index1] = nums[index2];
                index1++;
                index2++;
            } else {
                index2++;
            }
        }

        while (index1 < nums.size()) {
            nums[index1] = 0;
            index1++;
        }
    }
};
// @lc code=end

