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
    void reorderList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        ListNode *tmp = nullptr;
        while (curr != nullptr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode *secondHalf = prev;
        ListNode *firstHalf = head;
    
        while (secondHalf != nullptr) {
            ListNode *tmp1 = firstHalf->next;
            ListNode *tmp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;

            firstHalf = tmp1;
            secondHalf = tmp2;
        }

        
        

    }



};
