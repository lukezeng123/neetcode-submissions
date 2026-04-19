class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            cout << " hi: " << l << r << endl;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] > nums[r]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return nums[0];
    }
};
