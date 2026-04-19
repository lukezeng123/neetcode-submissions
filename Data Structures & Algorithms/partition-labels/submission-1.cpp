class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }
        int l = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            l++;
            end = max(end, last[s[i]]);
            if (i == end) {
                res.push_back(l);
                l = 0;
            }
        }
        return res;
    }
};
