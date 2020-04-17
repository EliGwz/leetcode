/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return (l1 == NULL ? l2 : l1);
        }

        ListNode *newHead, *prev;
        if (l1->val < l2->val) {
            newHead = l1;
            prev = l1;
            l1 = l1->next;
        } else {
            newHead = l2;
            prev = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                prev->next = l1;
                prev = prev->next;
                l1 = l1->next;
            } else {
                prev->next = l2;
                prev = prev->next;
                l2 = l2->next;
            }
        }

        if (l1 != NULL) {
            prev->next = l1;
        }

        if (l2 != NULL) {
            prev->next = l2;
        }

        return newHead;
    }
};
// @lc code=end

