class Solution {

    int dfs(vector<int>& nums, int target, int i, int sum) {
        if (i == nums.size() && sum != target) return 0;
        if (i == nums.size()) return 1;
        return dfs(nums,target, i + 1, sum + nums[i]) + dfs(nums,target, i + 1, sum - nums[i]);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return dfs(nums,target,0,0);
    }
};
