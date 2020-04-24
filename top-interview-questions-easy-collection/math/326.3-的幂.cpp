/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
#include <cfloat>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;

        double res = log10(n) / log10(3);

        // cout << res << " " << (int)res << "  " << FLT_EPSILON <<  endl;
        if ((res - (int)res) == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end

