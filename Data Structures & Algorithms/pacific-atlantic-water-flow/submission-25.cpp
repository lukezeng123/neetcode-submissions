class Solution {
public:
    bool dfs_a(int i, int j, vector<vector<int>>& heights, bool visited[105][105]) {
        visited[i][j] = true;

        if (j == heights[0].size() - 1 || i == heights.size() - 1) {
            return true;
        }
        bool res = false;

        if (i - 1 >= 0 && heights[i - 1][j] <= heights[i][j] && !visited[i - 1][j]) {
            res |= dfs_a(i-1,j,heights,visited);
        }

        if (i + 1 < heights.size() && heights[i + 1][j] <= heights[i][j] && !visited[i + 1][j]) {
            res |= dfs_a(i+1,j,heights,visited);
        }

        if (j + 1 < heights[0].size() && heights[i][j + 1] <= heights[i][j] && !visited[i][j + 1]) {
            res |= dfs_a(i,j + 1,heights,visited);
        }

        if (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j] && !visited[i][j - 1]) {
            res |= dfs_a(i,j - 1,heights,visited);
        }
        return res;
    }

     bool dfs_p(int i, int j, vector<vector<int>>& heights, bool visited[105][105]) {
        visited[i][j] = true;
        if (j == 0 || i == 0) {
            return true;
        }
        bool res = false;

        if (i - 1 >= 0 && heights[i - 1][j] <= heights[i][j] && !visited[i - 1][j]) {
            res |= dfs_p(i-1,j,heights,visited);
        }

        if (i + 1 < heights.size() && heights[i + 1][j] <= heights[i][j] && !visited[i + 1][j]) {
            res |= dfs_p(i+1,j,heights,visited);
        }

        if (j + 1 < heights[0].size() && heights[i][j + 1] <= heights[i][j] && !visited[i][j + 1]) {
            res |= dfs_p(i,j + 1,heights,visited);
        }

        if (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j] && !visited[i][j - 1]) {
            res |= dfs_p(i,j - 1,heights,visited);
        }
        return res;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool visiteda[105][105] = {false};
                bool visitedp[105][105] = {false};
                if (dfs_a(i,j,heights, visiteda) && dfs_p(i,j,heights, visitedp)) {
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }
};
