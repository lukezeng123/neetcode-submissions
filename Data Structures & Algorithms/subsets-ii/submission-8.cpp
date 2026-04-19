class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> part;
        dfs(0,nums, part);
        return res;

    }

    void dfs(int i, vector<int> &nums, vector<int> &part) {
        if (i == nums.size()) {
            res.push_back(part);
            return;
        }
        part.push_back(nums[i]);
        dfs(i + 1, nums, part);
        part.pop_back();
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) j++;
        dfs(j, nums, part);
    }
};
