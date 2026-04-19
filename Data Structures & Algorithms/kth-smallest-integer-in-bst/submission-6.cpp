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
    int kthSmallest(TreeNode* root, int k) {
        int left = leftCount(root->left);
        if (left > k - 1) {
            return kthSmallest(root->left, k);
        } else if (left == k - 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - left - 1);
        }
    }

    int leftCount(TreeNode* root) {
        if (!root) return 0;
        return 1 + leftCount(root->right) + leftCount(root->left);
    }

};
