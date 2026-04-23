/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* cur = node;
        if (cur->right) {
            cur = cur->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        }
        while (cur->parent && cur->parent->right == cur) {
            cur = cur->parent;
        }

        cur = cur->parent;
        return cur;
        
    }


};
