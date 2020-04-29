/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < i+1; j++) {
                if (i == 0)
                    ans[i].push_back(1);
                else {
                    if (j == 0 || j == i)
                        ans[i].push_back(1);
                    else {
                        int temp = ans[i - 1][j - 1] + ans[i - 1][j];
                        ans[i].push_back(temp);
                    }
                }
               
            }
        }
        return ans;
    }
};
// @lc code=end

