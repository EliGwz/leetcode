/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
            return true;
        else if (s.length() == 1)
            return false;
        else {

            stack<int> b;
            for (int i = 0; i<s.length(); i++) {
                if (b.empty())
                    b.push(s[i]);
                else {
                    switch (s[i]) {
                        case ')':
                            if (b.top() == '(')
                                b.pop();
                            else
                                b.push(s[i]);
                            break;
                        case ']':
                            if (b.top() == '[')
                                b.pop();
                            else
                                b.push(s[i]);
                            break;
                        case '}':
                            if (b.top() == '{')
                                b.pop();
                            else
                                b.push(s[i]);
                            break;
                        default:
                            b.push(s[i]);
                    }
                }
            }
            if (b.empty())
                return true;
            else
                return false;
        }
    }
};
// @lc code=end

