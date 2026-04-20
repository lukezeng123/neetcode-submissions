class Solution {
    int dfs(int u, vector<int>& visited, vector<vector<int>>& adj) {
        if (visited[u]) return 0;
        visited[u] = 1;
        int ans = 0;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                ans = max(ans, 1 + dfs(v,visited, adj));
            }
        }
        return ans;
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // dfs from every edge??
        
        vector<vector<int>> adj(edges.size() + 1);
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        } 
        for (int i = 0; i < edges.size() + 1; i++) {
            vector<int> visited(edges.size() + 1, 0);
            ans = max(ans,dfs(i,visited,adj));
        } 
        return ans;
    }
};
