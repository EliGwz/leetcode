/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length() || needle.length() == 0) {
            return 0;
        }
        int p1 = 0, p2 = 0, start = -1;
        while (p1 < haystack.length()) {
            if (haystack[p1] != needle[p2]) {
                p1++;
                p2 = 0;
                start = -1;
            } else {
                if (p2 == 0)
                    start = p1;
                if (p2 < needle.length()) {
                    p1++;
                    p2++;
                }
                if (p2 == needle.length())
                    break;
            }
        }
        return start;
    }
};
// @lc code=end

