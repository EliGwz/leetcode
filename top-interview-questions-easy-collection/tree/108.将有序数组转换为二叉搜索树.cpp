/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = nullptr;
        if (nums.size() == 0) {
            return root;
        } else if (nums.size() == 1) {
            root = new TreeNode(nums[0]);
            return root;
        } else if (nums.size() == 2) {
            root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            return root;
        } else {
            queue<tuple<TreeNode*, int, int>> q;
            int start = 0, end = nums.size() - 1;
            int mid = (start + end) >> 1;
            root = new TreeNode(nums[mid]);
            q.push(tuple<TreeNode*, int, int>(root, start, end));
            TreeNode *p;
            while (!q.empty()) {
                for (int i=0; i<q.size(); i++) {
                    p = get<0>(q.front());
                    start = get<1>(q.front());
                    end = get<2>(q.front());
                    cout << p->val << " " << start << " " << end << endl;

                    mid = (start + end) >> 1;
                    if (start <= mid-1) {
                        p->left = new TreeNode(nums[(start+mid-1)>>1]);
                        q.push(tuple<TreeNode*, int, int>(p->left, start, mid-1));
                    }

                    if (mid+1 <= end) {
                        p->right = new TreeNode(nums[(mid+1+end)>>1]);
                        q.push(tuple<TreeNode*, int, int>(p->right, mid+1, end));   
                    }
                    q.pop();
                }  
                
            }
            
        }

        return root;
    }
};
// @lc code=end

