class Solution {
public:
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        return dfs(0,0,s,p, dp);
    }


    bool dfs(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        int m = s.size();
        int n = p.size();
        if (i == m) {
            if (j + 1 == n - 1 && p[j + 1] == '*') {
                return true;
            }
            cout << "hi" << endl;
            cout << i << " " << j << endl;
            return j == n;
        }
        
        if (j + 1 < n && p[j + 1] == '*') {
            if (s[i] == p[j] || p[j] == '.') {
                cout << "meow" << endl;
                return dfs(i + 1, j, s, p, dp) || dfs(i + 1, j + 2, s, p, dp) || dfs(i, j + 2, s, p, dp);
            } else {
                cout << "hihihihi" << endl;
                return dfs(i, j + 2, s, p, dp);
            }
        } else if (s[i] == p[j] || p[j] == '.') {
            cout << "poop" << endl;
            return dfs(i + 1, j + 1,s,p,dp);
        } else {
            cout << "moo" << endl;
            return false;
        }
        return false;
    }
};

// dp[i][j] is using getting to character i using up to character j
// 



