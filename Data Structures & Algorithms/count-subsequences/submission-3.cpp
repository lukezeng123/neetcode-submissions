class Solution {
public:
    int numDistinct(string s, string t) {
        // m and n
        // dp[i][j] num distinct using up to i and up to j
        // if s[i] = s[j] -> i + 1, j + 1
        // 
        // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
                cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[m][n];
    }
};
