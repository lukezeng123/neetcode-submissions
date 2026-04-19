class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1e9;
        }
        dp[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= i - j) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                    cout << 'h' << endl;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << dp[i] << endl;
        }
        return dp[nums.size() - 1];
    }
};
