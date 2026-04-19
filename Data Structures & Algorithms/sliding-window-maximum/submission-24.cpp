class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            // while (!q.empty() && q.back().second <= i - k) {
            //     q.pop_back();
            // }

            // if (q.empty() || nums[i] >= q.front().first) {
            //     cout << nums[i] << endl;
            //     q.push_front({nums[i], i});

            // }
            // if (i >= k - 1) {
            //     output.push_back(q.front().first);
            // } 
            while (!q.empty() && q.back().first <= nums[i]) {
                q.pop_back();
            }

            q.push_back({nums[i],i});
            while (!q.empty() && q.front().second <= i - k) {
                q.pop_front();
            }
            if (i >= k - 1)
                output.push_back(q.front().first);
        }
        return output;
    }
};
