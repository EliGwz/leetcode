/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        for (auto s:strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(s);
        }

        unordered_map<string, vector<string>>::iterator it;
        for (it = umap.begin(); it != umap.end(); it++) {
            ans.push_back(it->second);
        }

            return ans;
    }
};
// @lc code=end

