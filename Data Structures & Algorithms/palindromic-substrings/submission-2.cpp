class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            count++;
            int j = 1;
            while (i - j >= 0 && i + j < n) {
                if (s[i - j] != s[i + j]) break;
                j++;
                count++;
            }
            j = 0; 
            while (i - j >= 0 && i + j + 1< n) {
                if (s[i - j] != s[i + j + 1]) break;
                j++;
                count++;
            }
        }
        return count;
    }
};
