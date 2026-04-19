class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        vector<int> vals(m + 2, 1);
        for (int i = 0; i < m; i++) {
            vals[i + 1] = nums[i];
        }
        int n = m + 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
