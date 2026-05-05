class Solution {

    struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        int cnt = 0;

        vector<vector<int>> dirs = {
            {1,2}, {2,1}, {-1,2}, {-2,1},
            {1,-2}, {2,-1}, {-1,-2}, {-2,-1}
        };
        
        unordered_set<pair<int,int>, pair_hash> visited;
        queue<pair<int,int>> q;
        q.push({0,0});
        visited.insert({0,0});
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                auto [u,v] = q.front();
                if (u == x && v == y) return cnt;
                q.pop();
                
                for (auto& dir : dirs) {
                    if (u + dir[0] >= -4 && v + dir[1] >= -4 && !visited.contains({u + dir[0], v + dir[1]}) && u + dir[0] < 4 + x && v + dir[1] < 4 + y) {
                        visited.insert({u + dir[0], v + dir[1]});
                        q.push({u + dir[0], v + dir[1]});
                    } 
                }
            }
            cnt++;
        }
        return -1;


    }
};
