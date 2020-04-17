/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        else if (strs.size() == 1)
            return strs[0];
        else if (strs.size() == 2) {
            int minlen = min(strs[0].length(), strs[1].length());
            int i;
            for (i = 0; i < minlen; i++) {
                if (strs[0][i] != strs[1][i]) {
                    break;
                }
            }
            return strs[0].substr(0, i);
        } else {
            return longestCommonPrefix(strs, 0, strs.size()-1);
        }  
    }

    string longestCommonPrefix(vector<string>& strs, int start, int end) {
        int size = end - start + 1;
        if (size == 0)
            return "";
        else if (size == 1)
            return strs[start];
        else if (size == 2) {
            int minlen = min(strs[start].length(), strs[start+1].length());
            int i;
            for (i = 0; i < minlen; i++) {
                if (strs[start][i] != strs[start+1][i]) {
                    break;
                }
            }
            return strs[start].substr(0, i);
        } else {
            int mid = (start + end) / 2;
            string str1 = longestCommonPrefix(strs, start, mid);
            string str2 = longestCommonPrefix(strs, mid + 1, end);
            int minlen = min(str1.length(), str2.length());
            int i;
            for (i = 0; i < minlen; i++) {
                if (str1[i] != str2[i]) {
                    break;
                }
            }
            return str1.substr(0, i);
        }  
    }
};
// @lc code=end

