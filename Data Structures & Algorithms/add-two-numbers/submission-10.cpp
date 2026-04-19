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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *h = nullptr;
        int carry = 0;
        ListNode* prev = nullptr;
        while (cur1 != nullptr || cur2 != nullptr) {
            int cur1_val, cur2_val;
            if (cur1 == nullptr) {
                cur1_val = 0;
            } else {
                cur1_val = cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 == nullptr) {
                cur2_val = 0;
            } else {
                cur2_val = cur2->val;
                cur2 = cur2->next;
            }
            int val_ = cur1_val + cur2_val + carry;
            if (val_ >= 10) {
                carry = 1;
                val_ -=10;
            } else {
                carry = 0;
            }
            ListNode* cur = new ListNode;
            cur->val = val_;
            if (prev != nullptr) {
                prev->next = cur;
            } else {
                h = cur; 
            }
            prev = cur;
        }
        if (carry) {
            ListNode* cur = new ListNode;
            cur->val = 1;
            prev->next = cur;
        }
        return h;
    }
};
