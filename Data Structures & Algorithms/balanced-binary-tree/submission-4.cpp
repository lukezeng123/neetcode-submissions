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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1) return false;
        if (left == 0 && right == 0) return true;
        if (left == 1 && right == 0) return true;
        if (left == 0 && right == 1) return true;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(height(root->left) + 1, height(root->right) + 1);
    }
};
