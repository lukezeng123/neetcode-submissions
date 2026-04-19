class Solution {
public:
    int climbStairs(int n) {
        int ans[3];
        ans[0] = 0;
        ans[1] = 1;

        for (int i = 0; i < n; i++) {
            ans[2] = ans[0] + ans[1];
            ans[0] = ans[1];
            ans[1] = ans[2];
        }
        return ans[1];
    }
};
