/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode *slow = head, *fast = head->next;
        while (slow != fast && fast != nullptr) {
            slow = slow->next;
            if (fast->next != nullptr) fast = fast->next->next;
            else fast = fast->next;
        }

        if (fast == nullptr) return false;
        else return true;

    }
};
// @lc code=end

