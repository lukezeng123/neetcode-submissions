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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int leftMax = maxLength(root->left);
        int rightMax = maxLength(root->right);
        int maxSub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));  
        return max(leftMax + rightMax, maxSub);
    }

    int maxLength(TreeNode* root) {
        // if (root->left == NULL && root->right == NULL) {
        //     return 0;
        // }
        // if (root->left != NULL && root->right != NULL) {
        //     return max(diameterOfBinaryTree(root->left) + 1, diameterOfBinaryTree(root->right) + 1);
        // } else if (root->left != NULL) {
        //     return diameterOfBinaryTree(root->left) + 1;
        // } else {
        //     return diameterOfBinaryTree(root->right) + 1;
        // }
        if (!root) return 0;
        return 1 + max(maxLength(root->left), maxLength(root->right));
    }


    
};
