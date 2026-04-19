/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        invert(root);
        return root;
    }
    
private:
    void invert(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        if (root->left != nullptr && root->right != nullptr) {
            TreeNode *tmp = root->left; 
            root->left = root->right;
            root->right = tmp;
            invert(root->left);
            invert(root->right);
        } else if (root->left != nullptr) {
            root->right = root->left;
            root->left  = nullptr;
            invert(root->right);
        } else {
            root->left = root->right;
            root->right  = nullptr;
            invert(root->left);
        }
        

    }

};
