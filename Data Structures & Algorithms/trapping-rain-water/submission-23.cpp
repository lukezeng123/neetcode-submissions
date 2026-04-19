class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        int ans = 0;
        while (l < r) {
            if (leftMax > rightMax) {
                
                ans += min(leftMax, rightMax) - height[r];
                r--;
                rightMax = max(rightMax, height[r]);
            } else {
                
                ans += min(leftMax, rightMax) - height[l];
                l++;
                leftMax = max(leftMax, height[l]);
            }
        }
        return ans;
    }
};
