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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // everything before preorder[0] in inorder is in the left subtree. 
        // everything before preorder[1] in inorder 
        // iterate inorder until preorder[0]
        // then gives left subtree and right subtree
        // at preorder[i] find it and check left and right for the parents
        int n = preorder.size();
        if (n == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        int j = 0;
        while (j < n &&inorder[j] != preorder[0]) j++;

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + j + 1);
        vector<int> rightPre(preorder.begin() + j + 1, preorder.end());
        vector<int> rightIn(inorder.begin() + j + 1, inorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + j);

        root->right = buildTree(rightPre, rightIn);
        root->left = buildTree(leftPre, leftIn);
        return root;
    }
};
