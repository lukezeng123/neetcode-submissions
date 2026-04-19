class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(),key.end());
            m[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto [k, v] : m) {
            res.push_back(v);
        }
        return res;
    }
};
