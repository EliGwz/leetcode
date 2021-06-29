/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode* pre = nullptr;
    ListNode* cur = start;
    ListNode* nxt = start;
    while (cur != end) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        for (int i=0; i<k; i++) {
            if (end == nullptr) {
                return head;
            }
            end = end->next;
        }
        ListNode* newHead = reverse(start, end);

        head->next = reverseKGroup(end, k);
        return newHead;
    }
};
// @lc code=end

