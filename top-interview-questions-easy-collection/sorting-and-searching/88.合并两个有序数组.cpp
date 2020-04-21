/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        } else if (n == 0) {
            return;
        } else {
            int i = m-1, j = n-1;
            for (int k = m + n - 1; k >= 0; k--) {
                if (i < 0 && j >= 0) {
                    nums1[k] = nums2[j];
                    j--;
                } else if (i >= 0 && j < 0) {
                    break;
                } else {
                    if (nums1[i] < nums2[j]) {
                        nums1[k] = nums2[j];
                        j--;
                    } else if (nums1[i] == nums2[j]) {
                        nums1[k] = nums1[i];
                        i--;
                    } else {
                        nums1[k] = nums1[i];
                        i--;
                    }
                }
            }
        }

    }
};
// @lc code=end

