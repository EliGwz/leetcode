/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2)
            return s;

        if (s.length() == 2) {
            if (s[0] == s[1])
                return s;
            else
                return s.substr(0, 1);
        }

        int dp[s.length()][s.length()];
        for (int i = 0;i<s.length(); i++) 
            for (int j=0; j<s.length(); j++)
                dp[i][j] = 0;

        int length = 0, maxLength = 0;
        string res;

        for (int i=0; i<s.length(); i++) {
            dp[i][i] = 1;
            length = 1;

            if (length > maxLength) {
                maxLength = length;
                res = s.substr(i, length);
            }
        }

        for (int i=0; i<s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i + 1] = 1;
                length = 2;
            }

            if (length > maxLength) {
                maxLength = length;
                res = s.substr(i, length);
            }
        }

        for (int j = 2; j < s.length(); j++) {
            for (int i = 0; i < j-1; i++) {
                if (dp[i+1][j-1] == 0) {
                    dp[i][j] = 0;
                    continue;
                } else if (s[i] == s[j]){
                    dp[i][j] = 1;
                    length = j - i + 1;
                } else {
                    dp[i][j] = 0;
                    continue;
                }

                if (length > maxLength) {
                    maxLength = length;
                    res = s.substr(i, length);
                    cout << res << "-" << length << endl;
                }
            }
        }

        for (int i = 0;i<s.length(); i++) {
            for (int j=0; j<s.length(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
            return res;
    }
};
// @lc code=end

