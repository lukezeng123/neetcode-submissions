class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;

        for (auto e : slots1) {
            if (e[1] - e[0] < duration) continue;
            pq1.push({e[0],e[1]});
        }
        for (auto e : slots2) {
            if (e[1] - e[0] < duration) continue;
            pq2.push({e[0],e[1]});
        }
        
        while (!pq1.empty() && !pq2.empty()) {
            auto [s1,e1] = pq1.top();
            auto [s2,e2] = pq2.top();
            if (s1 >= s2 && e2 >= s1 + duration) {
                return {s1, s1+duration};
            } else if (s2 > s1 && e1 >= s2 + duration) {
                return {s2, s2+duration};
            }

            if (e1 > e2) {
                pq2.pop();
            } else {
                pq1.pop();
            }
        }
        return {};
    }
};
