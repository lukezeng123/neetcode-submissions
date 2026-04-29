class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.back() <= i - k) dq.pop_back();
            while (!dq.empty() && nums[i] >= nums[dq.front()]) dq.pop_front();
            dq.push_front(i);
            if (i >= k - 1) ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};
