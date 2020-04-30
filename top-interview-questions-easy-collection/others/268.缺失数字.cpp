/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 1 && nums[0] == 0)
            return 1;
        else if (nums.size() == 1 && nums[0] == 1)
            return 0;

        int sum = 0, n = INT_MIN;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                zero = true;
            if (nums[i] > n)
                n = nums[i];
        }

        int total = n * (n + 1) / 2;
        if (!zero)
            return 0;
        else {
            if (total == sum)
                return n + 1;
            else
                return total - sum;
        }
    }
};
// @lc code=end

