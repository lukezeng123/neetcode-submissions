class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;
        if (n + m != k) return false;
        for (int s = 1; s <= k; s++) {
            for (int i = max(0, s - m); i <= min(s, n); i++) {
                int j = s - i;
                dp[i][j] = (i > 0 &&dp[i - 1][j] && s1[i - 1] == s3[s - 1])|| (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[s - 1]);
            } 
        }
        return dp[n][m];
    }
};
