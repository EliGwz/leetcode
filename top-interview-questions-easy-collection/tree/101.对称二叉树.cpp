/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <iostream>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            long *array = new long[q.size()];
            int num = q.size();
            for (int i = 0; i < num; i++) {
                if (q.front() == NULL)
                    cout << "null ";
                else
                    cout << q.front()->val << " ";
                array[i] = (q.front() == NULL?LONG_MIN:q.front()->val);
                // cout << array[i] << " ";
                if (q.front()) q.push(q.front()->left);
                if (q.front()) q.push(q.front()->right);
                q.pop();
            }

            for (int i = 0; i < num/2; i++) {
                if (array[i] != array[num-1-i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

