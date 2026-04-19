class Solution {

public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> n;
        dfs(0, target, n, 0, nums);
        return res;
    }
    void dfs(int idx, int target, vector<int> m, int sum,vector<int>& nums) {
        if (sum == target) {
            res.push_back(m);
            return;
        }
        if (sum > target || idx == nums.size()) return;
        if (idx + 1 < nums.size()) {
            dfs(idx + 1, target, m, sum, nums);
        }
        m.push_back(nums[idx]);
        dfs(idx, target, m, sum + nums[idx], nums);
    }
};
