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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* GroupPrev = dummy;
        ListNode* cur = head;
        
        while (true) {
            ListNode* kth = getKthNode(GroupPrev, k);
            if (!kth) break;
            ListNode* GroupNext = kth->next;
            prev = GroupNext;
            
            while (cur != GroupNext) {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode* tmp = GroupPrev->next;
            GroupPrev->next = kth;
            GroupPrev = tmp;
        
        }
        return dummy->next;
    }

    ListNode* getKthNode(ListNode* start, int k) {
        while (start && k--) {
            start = start->next;
        }
        return start;
    }
};
