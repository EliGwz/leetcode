/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
#include <stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }

        stack<int> s;
        int i = 0;
        p = head;
        while (p != NULL) {
            if (count%2 == 1 && i == count/2) {
                p = p->next;
                i++;
                continue;
            }
                

            if (!s.empty()) {
                if (s.top() == p->val) {
                    s.pop();
                } else {
                    s.push(p->val);
                }
            } else {
                s.push(p->val);
            }
            p = p->next;
            i++;
        }
        if (s.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

