class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int count[26] = {0};
      int left = 0;
      int right = 0;
        int res = 0;

      for (int i = 0; i < s.length(); i++) {
        right = i;
        int maxx = 0;
        count[s[i] - 'A']++;
        for (int i = 0; i < 26; i++) {
            maxx = max(maxx, count[i]);
        }
        if (right - left + 1 - maxx <= k) {
            res = right - left + 1;
        } else {
            count[s[left] - 'A']--;
            left++;

        }
      }
      
      return res;
    }
};
