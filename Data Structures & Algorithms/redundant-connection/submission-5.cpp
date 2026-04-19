class Solution {
public:
    int parent[105];
    int subtree_size[105];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (root(u) == root(v)) return {u, v};
            join(u, v);
        }
        return {};
    }

    


private:
    int root(int x) {
        return parent[x] == x ? x : parent[x] = root(parent[x]);
    }


private:
    void join(int x, int y) {
        x = root(x); y = root(y);
        if (subtree_size[x] > subtree_size[y]) swap(x, y);
        parent[y] = x;
        subtree_size[y] += subtree_size[x];
    }
private:
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            subtree_size[i] = 1;
        }
    }
};





