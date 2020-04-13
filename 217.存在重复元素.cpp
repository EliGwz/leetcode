/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;

        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++){
            if (set.find(nums[i]) == set.end()) {
                set.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

