/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i=1;
        
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        
        while (tmp || !s.empty()) {
            if (tmp) {
                s.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = s.top();
                s.pop();
                if (i == k) {
                    return tmp->val;
                } else {
                    i++;
                }
                tmp = tmp->right;
            }
        }
        return tmp->val;
    }
};