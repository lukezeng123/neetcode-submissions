class Solution {
public:
    int trap(vector<int>& height) {
        // left max and right max
        // left >= right left = right and ans iterate agiana nd calc water

        int leftMax = 0;
        
        int ans = 0;
        int n = height.size();
        int rightMax = 0;
        int i = 0;
        int highest = 0;
        
        for (int i = 0; i < n; i++) {
            if (height[highest] < height[i]) {
                highest = i;
            }
        }
        for (int i = 0; i < highest; i++) {
            if (height[i] > leftMax) {
                leftMax = height[i];
            } else {
                ans += leftMax - height[i];
            }
        }
        for (int i = n - 1; i > highest; i--) {
            if (height[i] > rightMax) {
                rightMax = height[i];
            } else {
                ans += rightMax - height[i];
            }
        }
        return ans;

    }
};
