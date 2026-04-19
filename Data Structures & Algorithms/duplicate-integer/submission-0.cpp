class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> f;
        for (int n : nums) {
            f[n]++;
        }

        for (int n : nums) {
            if (f[n] > 1) return true;
        }
        return false;

    }
};
