class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[1005] = {0};
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i]) {
                for (int j = i; j <= i + nums[i]; j++) {

                    cout << j <<  i << "with " << nums[i] << endl;
                    dp[j] = 1;
                }
            }
        }
        if (dp[nums.size() - 1]) return true;
        return false;
    }
};
