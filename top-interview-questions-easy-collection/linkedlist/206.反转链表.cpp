/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = head;
        ListNode *newHead = NULL;
        head = head->next;
        while (prev != NULL) {
            prev->next = newHead;
            newHead = prev;
            prev = head;
            if (prev == NULL)
                break;
            head = head->next;
        }
        return newHead;
    }
};
// @lc code=end

