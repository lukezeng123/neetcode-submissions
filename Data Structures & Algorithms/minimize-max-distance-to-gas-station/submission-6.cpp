class Solution {

public:

    bool possible(vector<int>& stations, int k, double mid) {
        int needed = 0;
        for (int i = 1; i < stations.size(); i++) {
            // how to do this
            needed += (stations[i] - stations[i - 1]) / mid;
        }
        return needed <= k;


    }
    double minmaxGasDist(vector<int>& stations, int k) {
        // binary search

        double left = 0;
        double right = 10'000'000;
        double ans = 0;
        double mid;
        while (right - left > 1e-6) {
            mid = (left + right) / 2.0;
            if (possible(stations,k,mid)) {
                ans = mid;
                right = mid;
            } else {
                left = mid;
            }
        }
        return ans;


    }
};
