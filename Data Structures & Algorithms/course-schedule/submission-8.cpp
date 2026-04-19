class Solution {
    vector<vector<int>> adj;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        adj.resize(n);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }

    bool dfs(int cur) {
        if (visiting.count(cur)) return false;
        if (adj[cur].empty()) return true;
        visiting.insert(cur);
        for (auto& nei : adj[cur]) {
            if (!dfs(nei)) return false;
            
        }
        visiting.erase(cur);
        adj[cur].clear();
        return true;
    }


};
