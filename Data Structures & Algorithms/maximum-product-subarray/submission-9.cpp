class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int highest = 1, lowest = 1;
        int res = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                highest = 1;
                lowest = 1;
            }
            int tmp = lowest;
            lowest = min(nums[i], min(lowest * nums[i], highest * nums[i]));
            highest = max(nums[i], max(highest * nums[i], tmp * nums[i]));
            res = max(res, highest);
        }
        return res;
    }
};
