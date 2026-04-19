class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int t = 0;
        int mmax = 0;
        for (int i = 0; i < piles.size(); i++) {
            mmax = max(mmax, piles[i]);
        }
        int lo = 1;
        int hi = mmax;
        int mid = (hi + lo) / 2;

        while (lo <= hi) {
            mid = (hi + lo) / 2;
            if (timeTaken(piles, mid) > h) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
private:
    int timeTaken(vector<int>& piles, int k) {
        int t = 0;
        for (int i = 0; i < piles.size(); i++) {
            t += ((piles[i] + k - 1) / k) ;
        }
        return t;
    }
};
