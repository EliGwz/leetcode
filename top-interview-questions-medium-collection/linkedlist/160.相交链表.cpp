/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *p1 = headA, *p2 = headB;
        int flag1 = 1, flag2 = 1;
        while (1) {
            // cout << p1->val << "-" << p2->val << endl;

            if (p1 == p2) {
                return p1;
            }

            if (flag1 && p1->next == nullptr) {
                flag1 = 0;
                p1 = headB;
            } else if (!flag1 && p1->next == nullptr) {
                return nullptr;
            } else {
                p1 = p1->next;
            }

            if (flag2 && p2->next == nullptr) {
                flag2 = 0;
                p2 = headA;
            } else if (!flag2 && p2->next == nullptr) {
                return nullptr;
            } else {
                p2 = p2->next;
            }
        }
    }
};
// @lc code=end

