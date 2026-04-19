class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> part;
        res.insert({});
        dfs(0,nums, part);
        return vector<vector<int>>{res.begin(),res.end()};

    }

    void dfs(int i, vector<int> &nums, vector<int> &part) {
        if (i == nums.size()) {
            return;
        }
        part.push_back(nums[i]);
        dfs(i + 1, nums, part);
        res.insert(part);
        part.pop_back();
        dfs(i + 1, nums, part);
        res.insert(part);
    }
};
