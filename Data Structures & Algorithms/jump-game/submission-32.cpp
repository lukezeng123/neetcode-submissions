class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[1005] = {0};
        dp[0] = 1;
        int furthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (furthest >= i) {
                furthest = max(furthest,i + nums[i]);
            }
        }
        if (furthest >= nums.size()-1) return true;
        return false;
    }
};
