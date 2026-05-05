class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n,false));
        using State = tuple<int, string, int, int>;
        priority_queue<State,vector<State>, greater<State>> pq;
        pq.push({0, "",ball[0],ball[1]});
        while (!pq.empty()) {
            auto [w, s, x, y] = pq.top();
            pq.pop();
            if (seen[x][y]) continue;
            seen[x][y] = true;
            if (x == hole[0] && y == hole[1]) return s;
            vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
            for (auto& dir : dirs) {
                int curRow = x;
                int curCol = y;
                int l = 0;
                while (curRow + dir[0] >= 0 && curCol + dir[1] >= 0 && curRow + dir[0] < m && curCol + dir[1] < n && maze[curRow + dir[0]][curCol + dir[1]] == 0) {
                    curRow += dir[0];
                    curCol += dir[1];
                    if (curRow == hole[0] && curCol == hole[1]) break;
                    l++;
                }
                string letter;
                if (dir[0] == -1) letter = "u";
                if (dir[0] == 1) letter = "d";
                if (dir[1] == 1) letter = "r";
                if (dir[1] == -1) letter = "l";
                // cout << l << endl;
                if (curRow != x || curCol != y) {
                    pq.push({l + w, s + letter, curRow, curCol});
                }
                
            }
        }
        return "impossible";
    }
};
