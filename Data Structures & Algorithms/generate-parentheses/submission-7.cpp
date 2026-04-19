class Solution {
public:
    vector<string> strs;
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n, "");
        return strs;
    }

    void dfs(int left, int right, int n, string s) {
        if (s.length() == n * 2) {
            strs.push_back(s);
            return;
        }
        if (left > right)dfs(left, right + 1, n,s + ')');
        if (left < n) dfs(left + 1, right,n, s + '(');
        
    }
};
