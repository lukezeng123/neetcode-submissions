class Solution {
public:
    void dfs_a(int i, int j, vector<vector<int>>& heights, bool (&visited)[105][105]) {
        visited[i][j] = true;

        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !visited[i - 1][j]) {
            dfs_a(i-1,j,heights,visited);
        }

        if (i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j] && !visited[i + 1][j]) {
            dfs_a(i+1,j,heights,visited);
        }

        if (j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j] && !visited[i][j + 1]) {
            dfs_a(i,j + 1,heights,visited);
        }

        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !visited[i][j - 1]) {
            dfs_a(i,j - 1,heights,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        bool visiteda[105][105] = {false};
        bool visitedp[105][105] = {false};
                vector<vector<int>> res;

        for (int i = 0; i < r; i++) {
            dfs_a(i,0,heights,visiteda);
        }

        for (int j = 0; j < c; j++) {
            dfs_a(0,j,heights,visiteda);
        }

        for (int i = r - 1; i >=0; i--) {
            dfs_a(i,c - 1,heights,visitedp);
        }

        for (int j = c - 1; j >= 0; j--) {
            dfs_a(r - 1,j,heights,visitedp);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visiteda[i][j] && visitedp[i][j]) {
                    res.push_back(vector<int>{i,j});
                }
            }
        }

        
        return res;
    }
};
