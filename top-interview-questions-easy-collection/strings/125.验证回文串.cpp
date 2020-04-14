/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() < 2) return true;

        for (int i=0; i<s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = (s[i] - 'A' + 'a');
            }
        }

        int p1 = 0, p2 = s.length()-1;
        while (p1 <= p2) {
            while (!isCharOrNum(s[p1])) {
                if (p1+1 >= s.length()) break;
                p1++;
                
            }

            while(!isCharOrNum(s[p2])) {
                if (p2-1 < 0) break;
                p2--;
            }

            if (p1 >= p2) break;
            
            if (s[p1] != s[p2]) return false;
            else {
                p1++;
                p2--;
            }
        }
        return true;
    }

    bool isCharOrNum(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
        else return false;
    }
};
// @lc code=end

