/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1) == true)
            return 1;

        int start = 1, end = n, mid;
        while (start != end - 1) {
            mid = start + ((end - start) >> 1);
            if (isBadVersion(mid) == false) {
                start = mid;
            } else if (isBadVersion(mid) == true) {
                end = mid;
            }
        }

        if (isBadVersion(start) == true)
            return start;
        else if (isBadVersion(end) == true)
            return end;
        else
            return 0;
    }
};
// @lc code=end

