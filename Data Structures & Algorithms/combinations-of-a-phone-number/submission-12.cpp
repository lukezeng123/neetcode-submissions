class Solution {
public:
    set<string> res;
    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<char> part;
        dfs(0, digits, part);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(int i, string &digits, vector<char> &part) {
        if (i == digits.size()) {
            res.insert(string{part.begin(),part.end()});
            return;
        }
        for (auto c : letters[digits[i] -'0']) {
            part.push_back(c);
            dfs(i + 1, digits, part);
            part.pop_back();
        }
    }
};
