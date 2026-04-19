class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        unordered_map<int, int> one;
        unordered_map<int, int> two;
        for (int i = 0; i < l1; i++) {
            one[s1[i] - 'a']++;
        }
        for (int i = 0; i < l2; i++) {

            two[s2[i] - 'a']++;
            if (i + 1 > l1) {
                int outKey = s2[i - l1] - 'a';
                // 1) decrement first:
                if (--two[outKey] == 0) {
                    // 2) only erase when it just hit zero
                    two.erase(outKey);
                }
            }
            if (one == two) return true;
        }
        return false;
    }
};
