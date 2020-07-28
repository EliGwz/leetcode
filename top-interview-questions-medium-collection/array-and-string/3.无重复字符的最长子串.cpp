/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2)
            return s.length();

        int start = 0, end = 1, maxL = 1, len = 1;
        unordered_map<char, int> umap;
        umap[s[start]] = start+1;
        while (end != s.length()) {
            if (umap[s[end]] > 0) {
                if (len > maxL)
                    maxL = len;

                int temp = umap[s[end]];
                for (int i = start; i<umap[s[end]]; i++) {
                    umap[s[i]] = 0;
                }

                umap[s[end]] = end + 1;
                start = temp;
                len = end - start + 1;
            } else {
                umap[s[end]] = end+1;
                len++;
            }

            end++;
        }

        if (len > maxL)
            maxL = len;

        return maxL;
    }
};
// @lc code=end

