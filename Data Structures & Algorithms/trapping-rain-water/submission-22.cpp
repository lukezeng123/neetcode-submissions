class Solution {
public:
    int trap(vector<int>& height) {
        // stack
        int n = height.size();

        vector<int> m1(n, 0);
        vector<int> m2(n, 0);
        m1[0] = height[0];
        for (int i = 1; i < n; i++) {
            m1[i] = max(height[i],m1[i - 1]);
            
        }
        m2[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            m2[i] = max(m2[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(m1[i],m2[i]) - height[i];
        }
        return ans;
    }
};
