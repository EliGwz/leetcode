/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++) {
            if (map.find(nums1[i]) == map.end()) {
                map.insert({nums1[i], 1});
            } else {
                map[nums1[i]]++;
            }
        }

        for (int i = 0; i < nums2.size();i++) {
            if (map.find(nums2[i]) != map.end()) {
                    v.push_back(nums2[i]);
                    if (--map[nums2[i]] == 0) {
                        map.erase(nums2[i]);
                    }

            }
        }

            return v;
    }
};
// @lc code=end

