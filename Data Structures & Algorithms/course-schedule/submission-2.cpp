class Solution {
public:

    unordered_map<int,vector<int>> preMap;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (int i = 0; i < prerequisites.size(); i++) {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
        

    }

    int dfs(int u) {
        if (visiting.count(u)) return 0;
        if (preMap[u].empty()) return 1;
        visiting.insert(u);
        for (int v : preMap[u]) {
           if (!dfs(v)) return false;
        }
        visiting.erase(u);
        preMap[u].clear();
        return 1;
    }

};
