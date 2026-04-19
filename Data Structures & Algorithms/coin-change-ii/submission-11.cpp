class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n][amount + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;  
        }
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;    
            }
        }
    
        
        for (int j = 1; j <= amount; j++) {
            for (int i = 1; i < n; i++) {
                if (j - coins[i] >= 0) {
                    dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][amount];
        

        
        

    }
};
