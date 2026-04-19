class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_inc = prices[0];
        int max_inc = 0;
        int highest = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                max_inc = prices[i];
                highest = max(max_inc - min_inc, highest);
            } else {
                min_inc = min(prices[i], min_inc);
                max_inc = 0;
            }
        }

        return highest;

    }
};
