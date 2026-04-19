class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> nums;
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry && digits[i] == 9) {
                nums.push_back(0);
            } else {
                if (carry) {
                    nums.push_back(digits[i] + 1); 
                } else {
                    nums.push_back(digits[i]); 
                }
               carry = false;
            }
        }
        if (carry) nums.push_back(1);
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
