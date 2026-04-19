class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto &w : wordDict) {
            dict.insert(w);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j + 1)) != 0) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
