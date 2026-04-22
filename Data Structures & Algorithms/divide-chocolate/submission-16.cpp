class Solution {

    bool possible(vector<int>& sweetness, int mid, int k) {
        int cur = 0;
        int segments = 0;
        for (int i = 0; i < sweetness.size(); i++) {
            cur += sweetness[i];
            if (cur >= mid) {
                cur = 0;
                segments++;
            }
        }
        return segments >= k + 1;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        // binary search
        if (k== 0 ) return accumulate(sweetness.begin(), sweetness.end(), 0);
        int l = 0;
        int r = accumulate(sweetness.begin(), sweetness.end(), 0) / k;
        int mid;
        int ans = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (possible(sweetness, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
