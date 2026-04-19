class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<multiset<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) s.insert({nums[i],nums[j],nums[k]});
                }  
            }
        }
        vector<vector<int>> res;
        for (auto i : s) {
            res.push_back({i.begin(), i.end()});
        }
        return res;
    }
};
