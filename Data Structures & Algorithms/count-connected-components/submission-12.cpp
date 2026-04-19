class Solution {
public:
    int parent[100];
    int size[100];
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (auto const &e: edges) {
            merge(e[0],e[1]);
        }

        set<int> res;
        for (int i = 0; i < n; i++) {
            res.insert(find(parent[i]));
        }
        return res.size();
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        int u_size = size[find(u)];
        int v_size = size[find(v)];
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) return;
        if (u_size > v_size) {
            parent[rv] = ru;
            size[ru] = size[ru] + size[rv];
        } else {
            parent[ru] = rv;
            size[rv] = size[ru] + size[rv];
        }
    }
};
