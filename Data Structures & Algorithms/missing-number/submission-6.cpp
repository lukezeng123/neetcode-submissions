class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int count = (n * (n + 1)) / 2;
        for (int i = 0; i < n; i++) {
            count -= nums[i];
        }
        if (count < 0) return n + 1;
        return count;
    }
};
