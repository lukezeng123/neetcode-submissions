class Solution {
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int area = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    area = max(area, dfs(r,c, grid));
                }
            }
        }
        return area;
    }

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++) {
            res += dfs( r + directions[i][0], c + directions[i][1], grid);
        }
        return res;
    }
};
