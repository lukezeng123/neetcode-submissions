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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        ListNode* curr = head;
        int N = 0;
        while (curr) {
            curr = curr->next;
            N++;
        }
        if (N == n) return head->next;
        int idx = N - n -1;
        curr = head;
        cout << N << "  " << n;
        while (idx--) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;



    }
};
