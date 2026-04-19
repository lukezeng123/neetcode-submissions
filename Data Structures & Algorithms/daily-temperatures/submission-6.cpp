class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> n;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!n.empty() && n.top().first < temperatures[i]) {
                res[n.top().second] = i - n.top().second;
                n.pop();
            }
            n.push({temperatures[i], i});
        }
        return res;
    }
};
