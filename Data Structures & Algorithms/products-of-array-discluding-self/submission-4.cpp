class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int has_zero = 0;
        int has_num = 0;
        for (int num : nums) {
            if (num != 0) {
                total *= num;
                has_num = 1;
            }
            else  has_zero++;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {

                if (has_num && has_zero < 2) res.push_back(total);
                else res.push_back(0);
                
                
            }
            else {
                if (has_zero) res.push_back(0);
                else res.push_back(total / nums[i]);
            }
        }
        return res;
    }
};
