class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][j] using up to coin i getting a total of t
        int n = coins.size();
        int dp[10005];
        fill(dp, dp + 10005, 10005);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j] && dp[i - coins[j]] != 10005) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] == 10005) return -1;
        return dp[amount];
    }
};
