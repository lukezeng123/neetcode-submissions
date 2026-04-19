class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> highest = {0,0};
        for (int i = 0; i < n; i++) {
            int length = 1;
            int l = i - 1; int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                length +=2;
                l--;
                r++;
            }
            if (length > highest.first) {
                highest = {length, l + 1};
            }

            length = 0;
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                length +=2;
                l--;
                r++;
            }
            if (length > highest.first) {
                highest = {length, l + 1};
            }
        }
        return s.substr(highest.second, highest.first);
    }
};
