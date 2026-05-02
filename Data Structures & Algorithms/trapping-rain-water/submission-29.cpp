class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int rt = 0;
        int L = 0;
        int R = height.size() - 1;
        int maxL = height[L];
        int maxR = height[R];
        while (L < R) {
            if (maxL < maxR) {
                L++;
                maxL = max(maxL, height[L]);
                rt += maxL - height[L];
            } else {
                R--;
                maxR = max(maxR, height[R]);
                rt += maxR - height[R];
            }
        }
        return rt;
    }
};
