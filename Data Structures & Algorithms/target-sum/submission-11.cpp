class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(40000, 0));
        dp[0][20000] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j < 40000; j++) {
                dp[i][j+ nums[i - 1]] += dp[i-1][j];
                dp[i][j- nums[i - 1]] += dp[i-1][j];
            }
        }
        return dp[nums.size()][target + 20000];
    }
};
