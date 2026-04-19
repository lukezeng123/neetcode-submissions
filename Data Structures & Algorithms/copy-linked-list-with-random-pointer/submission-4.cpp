/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> lookup;
        Node *curr = head;
        while (curr) {
            lookup[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            lookup[curr]->next = lookup[curr->next];
            lookup[curr]->random = lookup[curr->random];
            curr = curr->next;
        }
        return lookup[head];

        
    }
};
