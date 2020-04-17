/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *p = head, *target = NULL;
        
        while (p != NULL) {
            if (n == 0)
                target = head;
            else if (n < 0)
                target = target->next;
            p = p->next;
            n--;
        }
        if (target == NULL)
            head = head->next;
        else 
            target->next = target->next->next;

        return head;
    }
};
// @lc code=end

