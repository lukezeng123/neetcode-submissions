class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> t;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]) || isdigit(s[i])) t.push_back(tolower(s[i]));
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != t[t.size() - 1 - i]) return false;
            cout << 0;
        }
        return true;
    }
};
