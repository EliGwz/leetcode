/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

    void getNext(string p, int *next) {
        next[0] = -1;
        int p1 = 0, p2 = -1;
        while (p1 < p.length()) {
            if (p2 == -1 || p[p1] == p[p2]) {
                p1++;
                p2++;
                if (p1 == p.length())
                    break;
                next[p1] = p2;
            } else {
                p2 = next[p2];
            }
        }
    }

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0 || haystack == needle)
            return 0;
        else if (haystack.length() < needle.length())
            return -1;
        else {
            int *next = new int[needle.length()];
            getNext(needle, next);

       //     for (int i = 0; i < needle.length();i++)
      //          cout << next[i] << " ";

            int p1 = 0, p2 = 0, len1 = haystack.length(), len2 = needle.length();
            while ((p1 < len1) && (p2 < len2)) {
                if (p2 == -1 || haystack[p1] == needle[p2]) {
                    ++p1;
                    ++p2;
                } else {
                    p2 = next[p2];
                }
            }

            if (p2 == needle.length()) {
                return p1 - p2;
            } else {
                return -1;
            }   
        }
    }
};
// @lc code=end

