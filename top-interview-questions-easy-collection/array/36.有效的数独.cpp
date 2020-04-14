/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int H = 0, V = 0, P = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9;j++) {
                if (board[i][j] != '.') {
                    if (((H >> (board[i][j] - '1')) & 1) == 0) {
                        H += (1 << (board[i][j] - '1'));
                    } else {
                        return false;
                    }
                }

                if (board[j][i] != '.') {
                    if (((V >> (board[j][i] - '1')) & 1) == 0) {
                        V += (1 << (board[j][i] - '1'));
                    } else {
                        return false;
                    }
                }

                if (board[i/3*3+j/3][(i%3)*3+j%3] != '.') {
                    if (((P >> (board[i/3*3+j/3][(i%3)*3+j%3] - '1')) & 1) == 0) {
                        P += (1 << (board[i/3*3+j/3][(i%3)*3+j%3] - '1'));
                    } else {
                        return false;
                    }
                } 
            }
            H = 0;
            V = 0;
            P = 0;
        }

        return true;
    }
};
// @lc code=end

