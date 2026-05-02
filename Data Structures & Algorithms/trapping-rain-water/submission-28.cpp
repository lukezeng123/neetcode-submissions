class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> cur;
        cur.push_back(0);
        for (int i = 0; i < n; i++) {
            left[i] = cur.back();
            if (height[i] > height[cur.back()]) cur.push_back(i);
        }
        cur.clear();
        cur.push_back(n - 1);

        for (int i = n - 1; i >= 0; --i) {
            right[i] = cur.back();
            if (height[i] > height[cur.back()]) cur.push_back(i);
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans += max(min(height[left[i]],height[right[i]]) - height[i], 0);
        }
        return ans;
    }
};
