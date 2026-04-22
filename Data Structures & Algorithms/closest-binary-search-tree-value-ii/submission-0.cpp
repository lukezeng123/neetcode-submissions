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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // find the value in tree equal to it
        // then walk left and right / upwards
        vector<int> arr;
        dfs(root,arr);
        int left = lower_bound(arr.begin(),arr.end(),target) - arr.begin() - 1;
        int right = left + 1;
        vector<int> ans;
        while (ans.size() < k) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            } else if (right >= arr.size()) {
                ans.push_back(arr[left--]);
            } else if (abs(arr[left] - target) <= abs(arr[right] - target)) {
                ans.push_back(arr[left--]);
            } else {
                ans.push_back(arr[right++]);
            }
        }
        return ans;

    }
    void dfs(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        dfs(node->left,arr);
        arr.push_back(node->val);
        dfs(node->right,arr);
    } 
};
