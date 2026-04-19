class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> fs(26, 0);
        vector<int> ft(26, 0);
        for (const auto& c : s) {
            fs[c - 'a']++;
        }
        for (const auto& c : t) {
            ft[c-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (fs[i] != ft[i]) return false;
        }

        return true;
    }
};
