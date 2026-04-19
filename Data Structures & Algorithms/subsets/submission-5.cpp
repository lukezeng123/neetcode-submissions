class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            int idx = 0; 
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};
