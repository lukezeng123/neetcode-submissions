class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '0') return; 
        grid[x][y] = '0';
        if (x + 1 < grid.size()) {
            dfs(x + 1, y, grid);
        }
        if (x - 1 >= 0) {
            dfs(x - 1, y, grid);
        }
        if (y - 1 >= 0) {
            dfs(x, y - 1, grid);
        }
        if (y + 1 < grid[0].size()) {
            dfs(x, y+1, grid);
        }
    }
};
