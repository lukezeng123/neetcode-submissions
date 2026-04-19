class Solution {

    int dfs(vector<int>& nums, int target, int i, int sum, vector<vector<int>>& dp) {
        if (i == nums.size() && sum != target) return 0;
        if (i == nums.size()) return 1;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = dfs(nums,target, i + 1, sum + nums[i],dp) + dfs(nums,target, i + 1, sum - nums[i],dp);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(40000, -1));
        return dfs(nums,target+20000,0,20000,dp);
    }
};
