class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        pair<int, int> total = {0,0};
        int ans = -99999;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && total.second > 0) {
                ans = max(ans, total.first);
            }
            if (total.first + nums[i] < 0) {
                total.second = 0;
                total.first = 0;
                continue;
            }
            total.second++;
            total.first += nums[i];
            if (total.second > 0) {
                ans = max(ans, total.first);
            }
            
        }
        return ans;
    }
};
