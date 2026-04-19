class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int INF = 2147483647;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i - 1 >= 0 && grid[i - 1][j] != -1) {
                if (grid[i - 1][j] == INF) {
                    q.push({i-1, j});
                }
                grid[i - 1][j] = min(grid[i - 1][j], grid[i][j] + 1);
            }
            if (i + 1 < m && grid[i + 1][j] != -1) {
                if (grid[i + 1][j] == INF) {
                    q.push({i + 1, j});
                }
                grid[i + 1][j] = min(grid[i + 1][j], grid[i][j] + 1);
            }
            if (j - 1 >= 0 && grid[i][j - 1] != -1) {
                if (grid[i][j - 1] == INF) {
                    q.push({i, j - 1});
                }
                grid[i][j - 1] = min(grid[i][j - 1], grid[i][j] + 1);
            }
            if (j + 1 < n && grid[i][j + 1] != -1) {
                if (grid[i][j + 1] == INF) {
                    q.push({i, j + 1});
                }
                grid[i][j + 1] = min(grid[i][j + 1], grid[i][j] + 1);
            }
        }
    }
};
