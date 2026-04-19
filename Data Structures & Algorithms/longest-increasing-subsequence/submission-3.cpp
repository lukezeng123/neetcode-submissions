class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // longest increasing subsequence using index i
        int dp[1005];
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int highest = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    highest = max(highest, dp[j]);
                }
            }
            dp[i] = highest + 1;
        }
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            ans = max(ans, dp[j]);
        }
        return ans;
    }
};
