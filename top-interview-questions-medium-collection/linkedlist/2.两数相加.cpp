/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        while (p1 != nullptr && p2 != nullptr) {
            p1->val += p2->val;
            p1->val += carry;
            if (p1->val >= 10) {
                p1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            if (p1->next == nullptr || p2->next == nullptr)
                break;

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1->next == nullptr && p2->next != nullptr) {
            p1->next = p2->next;
            p1 = p1->next;
        } else if (p1->next != nullptr && p2->next == nullptr) {
            p1 = p1->next;
        } else if (p1->next == nullptr && p2->next == nullptr) {
            if (carry) {
                p1->next = new ListNode(carry);
            }

            return l1;
        }

        while (p1->next != nullptr) {
            p1->val += carry;
            if (p1->val >= 10) {
                p1->val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            p1 = p1->next;
        }

        p1->val += carry;
        if (p1->val >= 10) {
            p1->val %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        if (carry) {
            p1->next = new ListNode(carry);
        }

        return l1;
    }
};
// @lc code=end

