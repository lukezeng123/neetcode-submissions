class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int left = 0;
       int right = numbers.size() - 1;
       while (1) {
        if (numbers[right] + numbers[left] > target) {
            right--;
        } else if (numbers[right] + numbers[left] < target) {
            left++;
        } else {
            return {left + 1, right + 1};
        }
       }

    }
};
