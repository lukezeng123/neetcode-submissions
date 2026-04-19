class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while (!q.empty()) {
            queue<pair<int, int>> tmp;
            while (!q.empty()) {
                pair<int, int> c = q.front();
                int x = c.first;
                int y = c.second;
                q.pop();
                if (x - 1 >= 0 && grid[x-1][y] == 1) {
                    tmp.push({x-1,y});
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    tmp.push({x,y - 1});
                }
                if (x + 1 < grid.size() && grid[x+1][y] == 1) {
                    tmp.push({x+ 1,y});
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                    tmp.push({x,y + 1});
                }
                grid[x][y] = 2;
            }
            cout << tmp.front().first << endl;
          
            q = tmp;
            cout << q.front().first << endl << endl;
            if (!tmp.empty()) time++;
           
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
