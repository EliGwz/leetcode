/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1, sum = 0;
        while(left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) return vector<int>{left+1, right+1};
            else if (sum > target) right--;
            else if (sum < target) left++;
        }
        return vector<int>{};
    }
};
// @lc code=end

