/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev = node;
        while (node != NULL) {
            if (node->next != NULL) {
                node->val = node->next->val;
                node = node->next;
                if (node->next != NULL)
                    prev = prev->next;
            } else {
                delete prev->next;
                prev->next = NULL;
                break;
            }
        }
    }
};
// @lc code=end

