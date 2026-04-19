class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxSoFar = min(heights[0], heights[n - 1]) * (n - 1);

        int l = 0;
        int leftMax = heights[0];
        int rightMax = heights[n - 1];
        int r = n - 1;
        while (l <= r) {
            maxSoFar = max(min(heights[l], heights[r]) * (r - l), maxSoFar);
            cout << maxSoFar << endl;
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxSoFar;
    }
};
