class Solution {

public:
    bool dp[5005];
    bool canPartition(vector<int>& nums) {
        for (auto& d : dp) {
            d = false;
        }
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % 2 == 1) {
            return false;
        }
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = total; j >= nums[i]; j--) {
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        return dp[total / 2];
    }
};
