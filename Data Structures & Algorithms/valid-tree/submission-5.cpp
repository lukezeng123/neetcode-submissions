    


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[100];
        int visited[100] = {0};
        if (edges.size() != n-1) return false;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = 1;
            for (int v : adj[u]) {
                if (!visited[v]) q.push(v);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
