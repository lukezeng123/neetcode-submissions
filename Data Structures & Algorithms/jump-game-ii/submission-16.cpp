class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int mmax = 0;
        int cnt = 0;
        while (right < nums.size() - 1) {
            for (int j = left; j <= right; j++) {
                mmax = max(mmax, nums[j]);
            }
            left = right + 1;
            right += mmax;
            mmax = 0;
            cnt++;
        }
        return cnt;

        
    }
};
