/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int both=1, row=1, col=1;
        if (matrix[0][0] == 0) {
            both = 0;
        }


        for (int i = 0; i<matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size();j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else if ((i == 0 || j == 0) && (matrix[i][j] == 0)){
                    if (i == 0)
                        row = 0;
                    if (j == 0)
                        col = 0;
                } else if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (both == 0) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

        if (row == 0) {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

        if (col == 0) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end

