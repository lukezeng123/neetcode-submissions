class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x;
        vector<int> y;
        int l = grid.size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x.emplace_back(i);
                }
                if (i > 0 && grid[i - 1][j] != 0) {
                    grid[i][j] += grid[i - 1][j];
                }
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            while (grid[l-1][j]) {
                y.emplace_back(j);
                grid[l-1][j]--;
            }
        }
        int n = x.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (abs(x[i] - (n % 2 == 1 ? x[n/2] : ((x[n/2] + x[n/2 - 1]) / 2))));
            ans += (abs(y[i] - (n % 2 == 1 ? y[n/2] : ((y[n/2] + y[n/2 - 1]) / 2))));
        }
        return ans; 
    }
};
