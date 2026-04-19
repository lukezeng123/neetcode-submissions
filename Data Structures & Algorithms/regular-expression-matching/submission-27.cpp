class Solution {
    vector<vector<int>> dp;
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return dfs(0,0,s,p);
    }

    bool dfs(int i, int j, string& s, string& p) {
        int m = s.length();
        int n = p.length();
        cout << i << " " << j << endl;
        if (j == n) {
            return i == m;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < n && p[j + 1] == '*') {
            cout << "meow" << endl;
            dp[i][j] = dfs(i, j + 2,s,p) || (match && dfs(i + 1, j, s, p));
        } else {
            cout << "meow2" << endl;
            dp[i][j] = match && dfs(i + 1, j + 1,s,p);
        }
        return dp[i][j];
    }
};

// dp[i][j] is using getting to character i using up to character j



