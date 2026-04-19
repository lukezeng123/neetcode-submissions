class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int res = 0;
        for (int num : nums) {
            if (!m[num]) {
                m[num] = m[num - 1] + m[num + 1] + 1;
                m[num - m[num - 1]] = m[num];
                m[num + m[num + 1]] = m[num];
                res = max(res, m[num]);
            }
        }
        return res;
    }
};
