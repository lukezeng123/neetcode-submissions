class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> parts;
        dfs(0,0, s, parts);
        return res;
    }

    void dfs(int j, int i, string &s, vector<string> parts) {
        if (i >= s.size()) {
            if (i == j) {
                res.push_back(parts);
            }
            return;
        }

        if (isPali(s, j, i)) {
            parts.push_back(s.substr(j, i - j + 1));
            dfs(i + 1, i + 1, s, parts);
            parts.pop_back();
        }

        dfs(j, i + 1, s, parts);
    }

    bool isPali(string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    } 
};
