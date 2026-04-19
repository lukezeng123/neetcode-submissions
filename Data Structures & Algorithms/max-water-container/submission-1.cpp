class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxSoFar = min(heights[0], heights[n - 1]) * (n - 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxSoFar = max(maxSoFar, min(heights[i], heights[j]) * (j - i));
            }
        }   return maxSoFar;
    }
};
