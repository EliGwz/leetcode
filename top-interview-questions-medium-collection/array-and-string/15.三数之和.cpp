/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            // cout << nums[i] << " ";
            if (nums[i] > 0) {
                return ans;
            } else {
                if (i>0 && nums[i-1] == nums[i] ) continue;
                int left = i+1;
                int right = nums.size()-1;
                // cout << nums[left] << " " << nums[right] << endl;
                while (left < right) {
                    // cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;
                    if (nums[i] + nums[left] + nums[right] == 0) {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        if (left < right) left++;
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        if (left < right) right--;
                    } else if (nums[i] + nums[left] + nums[right] < 0) {
                        // while (nums[left] == nums[left+1]) left++;
                        left++;
                    } else if (nums[i] + nums[left] + nums[right] > 0) {
                        // while (nums[right] == nums[right-1]) right--;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

