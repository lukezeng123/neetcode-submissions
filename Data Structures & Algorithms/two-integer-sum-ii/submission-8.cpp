class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            m[target - numbers[i]] = i + 1;
        }
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(numbers[i]) != m.end()) {
                return {min(i + 1, m[numbers[i]]), max(i + 1, m[numbers[i]])};
            }
        }
        

    }
};
