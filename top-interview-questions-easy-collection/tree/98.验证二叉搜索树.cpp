/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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


#include <stack>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        long long output = -2147483649;

        while (p != nullptr || !s.empty()) {
           if (p) {
               s.push(p);
               p = p->left;
           } else {
               if ((long long)(s.top()->val) > output) {
                   cout << s.top()->val << endl;
                   output = s.top()->val;
               } else {
                   return false;
               }
               p = s.top()->right;
               s.pop();
           }
        }
        return true;
    }
};
// @lc code=end

