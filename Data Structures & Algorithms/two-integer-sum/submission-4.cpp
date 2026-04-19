class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> exists;

        for (int i = 0; i < n; i++) {
            exists[target - nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (exists[nums[i]] && i != exists[nums[i]]) return {i, exists[nums[i]]};
        }

        return {};

    }
};
