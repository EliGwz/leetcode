/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for(int i=0; i<s.size()/2; i++) {
            //swap(s[i], s[s.size()-i-1]);
            tmp = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = tmp;
        }
    }
};
// @lc code=end

