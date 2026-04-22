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
    void initSucc(TreeNode* node, double target, stack<TreeNode*>& succ) {
        while (node) {
            if (node->val >= target) {
                succ.push(node);
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    void initPred(TreeNode* node, double target, stack<TreeNode*>& pred) {
        while (node) {
            if (node->val < target) {
                pred.push(node);
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    int getSucc(double target, stack<TreeNode*>& succ) {
        int val = succ.top()->val;
        TreeNode* node = succ.top();
        succ.pop();
        node = node->right;
        while (node) {
            succ.push(node);
            node = node->left;
        }
        return val;
    }
    int getPred(double target, stack<TreeNode*>& pred) {
        int val = pred.top()->val;
        TreeNode* node = pred.top();
        pred.pop();
        node = node->left;
        while (node) {
            pred.push(node);
            node = node->right;
        }
        return val;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> succ;
        stack<TreeNode*> pred;
        initPred(root,target,pred);
        initSucc(root,target,succ);
        vector<int> ans;
        while (k--) {
            if (succ.empty()) {
                ans.push_back(getPred(target,pred));
            } else if (pred.empty()) {
                ans.push_back(getSucc(target,succ));
            } else if (abs(pred.top()->val - target) > abs(succ.top()->val - target)) {
                ans.push_back(getSucc(target,succ));
                
            } else {
                ans.push_back(getPred(target,pred));
            }
        }
        return ans;
    }
};
