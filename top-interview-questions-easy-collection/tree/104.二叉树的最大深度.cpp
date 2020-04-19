/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

#include <stack>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> s;
        int depth = 0, maxDepth = 0;
        TreeNode *p = root;

        while (p != nullptr || !s.empty()) {
            while (p != nullptr) {
                s.push(pair<TreeNode*, int>(p, ++depth));
                p = p->left;
            }
            p = s.top().first;
            depth = s.top().second;
            if (depth > maxDepth) maxDepth = depth;
            s.pop();
            p = p->right;
        }

        return maxDepth;
    }
};
// @lc code=end

