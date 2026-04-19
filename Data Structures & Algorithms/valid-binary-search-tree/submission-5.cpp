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
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1e9, 1e9);
    }

    bool dfs(TreeNode *node, int left, int right) {
        if (!node) return true;
        if (!(left < node->val && right > node->val)) return false;
        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
    }
};
