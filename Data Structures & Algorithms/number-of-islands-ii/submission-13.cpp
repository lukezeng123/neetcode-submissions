class Solution {
    vector<int> parent;
    vector<int> ssize;
    int components{};
    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        cout << "rx: " << rx << endl;
        cout << "ry: " << ry << endl;
        if (rx == ry) return false;
        
        if (ssize[rx] > ssize[ry]) {
            parent[ry] = parent[rx];
            ssize[rx] += ssize[ry];
        } else {
            parent[rx] = parent[ry];
            ssize[ry] += ssize[rx];
        }
        return true;
    }

    int root(int x) {
        if (x != parent[x]) {
            return parent[x] = root(parent[x]);
        }
        return x;

    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parent.resize(m * n);
        iota(parent.begin(),parent.end(), 0);
        ssize.resize(m*n, 1);
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> ans;
        for (auto& p : positions) {
            if (grid[p[0]][p[1]] == 1) {
                ans.push_back(components);
                continue;
            }
            grid[p[0]][p[1]] = 1;
            components++;
            for (auto& d : dir) {
                if (p[0] + d[0] >= m || p[0] + d[0] < 0 || d[1] + p[1] >= n || d[1] + p[1] < 0) continue;
                if (grid[p[0] + d[0]][p[1] + d[1]] == 1) {
                    cout << "meow" << endl;
                    if (unite(n * (p[0] + d[0]) +  p[1] + d[1], n * p[0] + p[1])) {
                        components--;
                    }
                }
            }
            ans.push_back(components);

        }
        return ans;
    }
};
