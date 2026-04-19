class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0, 0, nums, target);
    }

    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size() && total == target) return 1;
        if (i == nums.size() && total != target) return 0;
        return backtrack(i + 1, total - nums[i], nums, target) + backtrack(i + 1, total + nums[i], nums, target);
    }
};
