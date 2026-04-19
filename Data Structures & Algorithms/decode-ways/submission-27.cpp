class Solution {
public:
    
    int numDecodings(string s) {
        int dp[105] = {0};
        int n = s.size();
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] - '0' == 0) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1]; // take single digit
                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num >= 10 && num <= 26) {
                        dp[i] += dp[i + 2]; // take two digits
                    }
                }
            }
        }
        return dp[0];
    }
};
