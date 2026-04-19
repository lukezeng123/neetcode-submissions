class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> countT, window;
        for (int i = 0; i < t.size(); i++) {
            countT[t[i]]++;
        }
        int l = 0;
        int have = 0;
        int need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }
            while (have == need) {
                if (r - l + 1 < resLen) {
                    res = {l, r};
                    resLen = r - l + 1;
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
