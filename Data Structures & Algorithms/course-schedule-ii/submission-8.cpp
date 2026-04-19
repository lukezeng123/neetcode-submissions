class Solution {
    vector<int> output;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                dfs(numCourses,adj,indegree,i);
            }
        }
        if (output.size() != numCourses){
            return {};
        }
        return output;
    }

    void dfs(int numCourses, vector<vector<int>>& adj, vector<int>& indegree,int cur) {
        // push to output
        // for each neighbour decrement degree
        // if degree 0 then recurse

        output.push_back(cur);
        indegree[cur]--;
        for (int nei : adj[cur]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                dfs(numCourses,adj,indegree,nei);
            }
        }
    }
};
